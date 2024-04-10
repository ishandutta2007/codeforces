#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long llint;

const llint INF = 1000000000000000007;
const int MOD = 1000000007;
const int MAXN = 100005;

llint n, m, seed, vmax;
llint aa[MAXN];
set < pair <int, llint> > s;
set < pair <int, llint> > :: iterator it, it1, it2;
vector < pair <int, llint> > v;

llint mul (llint a, llint b, llint md) {
	return a*b%md;
}

llint pot (llint x, llint e, llint y) {
	if (e==0) return 1;
	if (e&1) {
		return mul(x, pot(x, e-1, y), y);
	} else {
		llint t=pot(x, e>>1, y);
		return mul(t, t, y);
	}
}

llint rnd () {
	llint ret=seed;
	seed=(seed*7+13)%MOD;
	return ret;
}

void gen (int l, int r) {
	v.clear();
	it1=s.upper_bound(make_pair(l, INF)); it1--;
	it2=s.upper_bound(make_pair(r, INF)); it2;
	for (it=it1; it!=it2; it++) {
		v.push_back(*it);
	}
}

int len (int ind) {
	return v[ind+1].first-v[ind].first;
}

void upit1 (int l, int r, llint x) {
	gen(l, r);
	if (v[0].first==l) s.erase(v[0]);
	s.insert(make_pair(l, v[0].second+x));
	if (!(it2==s.end() && r==n || r+1==it2->first)) {
		s.insert(make_pair(r+1, v[v.size()-1].second));
	}
	for (int i=1; i<v.size(); i++) {
		s.erase(v[i]);
		s.insert(make_pair(v[i].first, v[i].second+x));
	}
}

void upit2 (int l, int r, llint x) {
	//cout << "zvao " << l << " " << r << " " << x << endl;
	gen(l, r);
	//cout << "proso gen" << endl;
	if (v[0].first==l) s.erase(v[0]);
	//cout << "alo" << endl;
	if (!(it2==s.end() && r==n || r+1==it2->first)) {
		s.insert(make_pair(r+1, v[v.size()-1].second));
	}
	for (int i=1; i<v.size(); i++) {
		s.erase(v[i]);
	}
	s.insert(make_pair(l, x));
}

llint upit3 (int l, int r, llint x) {
	gen(l, r);
	if (v.size()==1) return v[0].second;
	vector < pair <llint, int> > p;
	p.push_back(make_pair(v[0].second, v[1].first-l));
	p.push_back(make_pair(v[v.size()-1].second, r-v[v.size()-1].first+1));
	for (int i=1; i<v.size()-1; i++) {
		p.push_back(make_pair(v[i].second, len(i)));
	}
	sort(p.begin(), p.end());
	int cnt=0;
	for (int i=0; i<p.size(); i++) {
		cnt+=p[i].second;
		if (x<=cnt) return p[i].first;
	}
}

llint upit4 (int l, int r, llint x, llint y) {
	gen(l, r);
	if (v.size()==1) return mul(r-l+1, pot(v[0].second%y, x, y), y);
	llint res=0;
	res+=mul(v[1].first-l, pot(v[0].second%y, x, y), y);
	res+=mul(r-v[v.size()-1].first+1, pot(v[v.size()-1].second%y, x, y), y);
	for (int i=1; i<v.size()-1; i++) {
		res+=mul(len(i), pot(v[i].second%y, x, y), y);
	}
	return res%=y;
}

int main () {
	cin >> n >> m >> seed >> vmax;
	for (int i=1; i<=n; i++) {
		aa[i]=rnd()%vmax+1;
		s.insert(make_pair(i, aa[i]));
		//cout << aa[i] << " ";
	}
	//cout << endl;
	for (int i=1; i<=m; i++) {
		int op=rnd()%4+1;
		int l=rnd()%n+1;
		int r=rnd()%n+1;
		if (l>r) swap(l, r);
		int x, y;
		if (op==3) x=rnd()%(r-l+1)+1; else x=rnd()%vmax+1;
		if (op==4) y=rnd()%vmax+1;
		/*cout << op << " " << l << " " << r << " " << x;
		if (op==4) cout << " " << y;
		cout << endl;*/
		if (op==1) {
			upit1(l, r, x);
		} else if (op==2) {
			upit2(l, r, x);
		} else if (op==3) {
			printf("%I64d\n", upit3(l, r, x));
		} else {
			printf("%I64d\n", upit4(l, r, x, y));
		}
		//cout << "prosao " << i << endl;
	}
	return 0;
}