#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second

bool letter(char c) {
	return 'A'<=c && c<='Z';
}
bool symbol(char c) {
	return c=='*' || c=='?' || c=='+';
}

struct art {
	int n, m;
	char *a;

	art(int N, int M) {
		n = N;
		m = M;
		a = new char[n*m];
		memset(a, ' ', n*m);
	}

	char* operator[](int x) const {
		return &a[m*x];
	}

	void copy(const art &b, int x, int y) {
		for (int i=0; i<b.n; ++i)
			memcpy(&a[(x+i)*m + y], &b.a[i*b.m], b.m);
	}
};

typedef vector<int> vi;

art parse_expr(char* s, int n);

art plusify(const art& t) {
	art a(t.n+2, t.m+6);
	a.copy(t, 0, 3);
	for (int i=1; i<a.n; ++i) a[i][0]=a[i][a.m-1] = '|';
	a[1][0] = a[1][a.m-1] = a[a.n-1][0] = a[a.n-1][a.m-1] = '+';
	a[1][1] = a[1][a.m-3] = '-';
	a[1][2] = a[1][a.m-2] = '>';
	for (int i=2; i<a.m-1; ++i) a[a.n-1][i] = '-';
	a[a.n-1][1] = '<';

	return a;
}
art questify(const art& t) {
	art a(t.n+2, t.m+6);
	a.copy(t, 2, 3);
	for (int i=1; i<4; ++i) a[i][0]=a[i][a.m-1] = '|';
	a[0][0] = a[0][a.m-1] = a[3][0] = a[3][a.m-1] = '+';
	a[3][1] = a[3][a.m-3] = '-';
	a[3][2] = a[3][a.m-2] = '>';
	for (int i=1; i<a.m-2; ++i) a[0][i] = '-';
	a[0][a.m-2] = '>';

	art y(a.n+1, a.m);
	y.copy(a, 1, 0);

	return y;
}
art starify(const art& t) {
	art u = questify(t);
	art a(t.n+5, t.m+6);
	a.copy(u, 0,  0);

	for (int i=5; i<a.n; ++i) a[i][0]=a[i][a.m-1] = '|';
	a[a.n-1][0] = a[a.n-1][a.m-1] = '+';
	for (int i=2; i<a.m-1; ++i) a[a.n-1][i] = '-';
	a[a.n-1][1] = '<';
	return a;
}

art parse_term(char *s, int n) {
	vector<art> terms;
	for (int i=0; i<n; ) {
		if (s[i]=='(') {
			int bal=1;
			int so = i;
			++i;
			while (bal) {
				if (s[i]=='(') ++bal;
				else if (s[i]==')') --bal;
				++i;
			}
			terms.push_back(parse_expr(s+so+1, i-so-2));
			continue;
		}
		if (symbol(s[i])) {
			if (s[i]=='+') terms.back() = plusify(terms.back());
			else if (s[i]=='?') terms.back() = questify(terms.back());
			else if (s[i]=='*') terms.back() = starify(terms.back());
			++i;
			continue;
		}
		int sz=0;
		int so=i;
		while (i<n && (
			(letter(s[i]) && (i==n-1 || !symbol(s[i+1]) ||sz==0))
		)) {
			sz++;
			++i;
		}

		art a(3, sz+4);
		for (int j=0; j<sz+4; ++j) a[0][j]=a[2][j]='-';
		for (int k=0; k<3; ++k) a[k][0]=a[k][a.m-1] = '+';
		for (int k=so; k<so+sz; ++k) a[1][2+k-so] = s[k];
		terms.push_back(a);
	}
	if (terms.size()==1) return terms[0];
	int sw=0, mh=0;
	for (int t=0; t<terms.size(); ++t) {
		sw += terms[t].m;
		mh = max(mh, terms[t].n);
	}
	art a(mh, sw + 2*(terms.size()-1));
	int curw=0;
	for (int t=0; t<terms.size(); ++t) {
		a.copy(terms[t], 0, curw);
		curw += terms[t].m;
		if (t!=terms.size()-1) {
			a[1][curw]='-';
			a[1][curw+1]='>';
		}
		curw+=2;
	}
	return a;
}

art parse_expr(char* s, int n) {
	int bal=0;
	vi ors;
	ors.push_back(-1);
	for (int i=0; i<n; ++i) {
		if (s[i]=='(') bal++;
		else if (s[i]==')') bal--;
		else if (s[i]=='|' && bal==0) ors.push_back(i);
	}
	ors.push_back(n);

	vector<art> terms;
	int sh=0, mw=0;
	for (int i=0; i<ors.size()-1; ++i) {
		terms.push_back(parse_term(s+ors[i]+1, ors[i+1]-ors[i]-1));
		mw = max(mw, terms.back().m);
		sh += terms.back().n;
	}
	if (terms.size()==1) return terms.back();
	art a(sh+terms.size()-1, mw+6);
	
	int curh = 0;
	int prev;
	for (int t=0; t<terms.size(); ++t) {
		a.copy(terms[t], curh, 3);
		for (int j=0; j<mw-terms[t].m+1; ++j)
			a[curh+1][3+terms[t].m+j] = '-';
		for (int i=prev+2; i<curh+1; ++i)
			a[i][0] = a[i][a.m-1] = '|';
		a[curh+1][0]='+';
		a[curh+1][1]='-';
		a[curh+1][2]='>';
		a[curh+1][a.m-2]='>';
		a[curh+1][a.m-1]='+';
		prev=curh;

		curh += terms[t].n+1;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char b[1000];
	string s; cin>>s;
	for (int i=0; i<s.size(); ++i) b[i]=s[i];
	art a = parse_expr(b, s.size());
	art y(a.n, a.m+6);
	y.copy(a, 0, 3);
	y[1][0] = 'S';
	y[1][1] = y[1][y.m-3] = '-';
	y[1][2] = y[1][y.m-2] = '>';
	y[1][y.m-1] = 'F';
	cout<<y.n<<' '<<y.m<<'\n';
	for (int i=0; i<y.n; ++i) {
		for (int j=0; j<y.m; ++j) cout<<y[i][j];
		cout<<'\n';
	}
}