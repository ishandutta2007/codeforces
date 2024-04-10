#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 10;
const int MOD = 666013;
int n, k, m, x[N], y[N], ans = 1e9;


int d(int xx, int yy, int i) {
	return abs(xx - x[i]) + abs(yy - y[i]);
}

void go(int xx, int yy, int i) {
	int dx = 1, dy = 1;
	if(xx > x[i]) dx = -1;
	if(yy > y[i]) dy = -1;

	while(xx != x[i]) {
		xx += dx;
		cout << xx << ' ' << yy << '\n';
	}
	while(yy != y[i]) {
		yy += dy;
		cout << xx << ' ' << yy << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			ans = min(ans, d(i, j, 0) + d(i, j, 1) + d(i, j, 2));

	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(d(i, j, 0) + d(i, j, 1) + d(i, j, 2) == ans ) {
				cout << ans + 1 << '\n';
				cout << i << ' ' << j << '\n';
				go(i, j, 0);
				go(i, j, 1);
				go(i, j, 2);
				return 0;
			}



	

}