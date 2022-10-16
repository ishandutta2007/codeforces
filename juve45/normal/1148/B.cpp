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

const int N = 200100;
int n, m, ta, tb, k, a[N], b[N], ans;
vector <pair<int, int> > v;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m >> ta >> tb >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i], v.push_back({a[i] + ta, 1});
	
	for(int i = 1; i <= m; i++)
		cin >> b[i], v.push_back({b[i], 2});

	sort(v.begin(), v.end());


	int nra = 0;
	int nrb = 0;
	ans = -1;
	for(auto i : v) {
		

		// dbg(i, nra, nrb);
		if(i.nd == 1) {
			nra = min(nrb, nra);
			nrb++;
		} else {
			if(min(nra, nrb) == k) {
				ans = i.st + tb;
			}
			nra = min(nra + 1, nrb);
		}
	}
	if(min(nra, nrb) == k) 
		ans = -1;
	cout << ans << '\n';

}