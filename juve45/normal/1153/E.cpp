#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 1020;
int n, lin[N], col[N];
vector <int> lins, cols;

int cbl(int line, int l, int r) {
	while(l != r) {
		int mid = (l + r) / 2;
		cout << "? " << line << ' ' << l << ' ' << line << ' ' << mid << endl;
		int tmp;
		cin >> tmp;
		if(tmp % 2 == 1) r = mid;
		else l = mid + 1;
	}
	return l;
}


int cbc(int col, int l, int r) {
	while(l != r) {
		int mid = (l + r) / 2;
		cout << "? " << l << ' ' << col << ' ' << mid << ' ' << col << endl;
		int tmp;
		cin >> tmp;
		if(tmp % 2 == 1) r = mid;
		else l = mid + 1;
	}
	return l;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i < n; i++) {
		cout << "? " << i << " 1 " << i << ' ' << n << endl;
		cin >> lin[i];
		lin[i] -= lin[i - 1];
	}
	lin[n] = lin[n - 1];
	for(int i = n - 1; i > 1; i--) lin[i] += lin[i - 1];

	for(int i = 1; i <= n; i++) if(lin[i] % 2 == 1) lins.push_back(i);

	for(int i = 1; i < n; i++) {
		cout << "? 1 " << i << ' ' << n << ' ' << i << endl;
		cin >> col[i];
		col[i] -= col[i - 1];
	}
	col[n] = col[n - 1];

	for(int i = n - 1; i > 1; i--) col[i] += col[i - 1];

	for(int i = 1; i <= n; i++) if(col[i] % 2 == 1) cols.push_back(i);

	int l1, c2, l2, c1;
	if(lins.size() == 2) {
		l1 = lins[0];
		l2 = lins[1];
		c1 = cbl(l1, 1, n);
		c2 = cbl(l2, 1, n);
	} else if(cols.size() == 2){
		c1 = cols[0];
		c2 = cols[1];
		l1 = cbc(c1, 1, n);
		l2 = cbc(c2, 1, n);
	} else  {
		assert(false);
	}
	cout << "! " << l1 << ' ' << c1 << ' ' << l2 <<  ' ' << c2 << endl;
}