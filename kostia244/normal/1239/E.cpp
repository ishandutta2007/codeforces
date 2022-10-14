// Problem: E. 
// Contest: Codeforces - Codeforces Round #594 (Div. 1)
// URL: https://codeforces.com/contest/1239/problem/E
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 26, C = 50500;
int n, a[N];
char p[N][C*N];
bitset<C*N> bt[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	bt[0][0] = 1;
	vector<int> a(n*2);
	for(auto &i : a) cin >> i;
	sort(all(a));
	vector<int> x {a[0]}, y {a[1]};
	a.erase(a.begin());a.erase(a.begin());
	int cz = 0;
	while(a.size() && a[0] == 0) {
		cz++;
		a.erase(a.begin());
	}
	int targ = n-1-((cz+1)/2);
	for(int i = 0; i < cz; i+=2)
		x.push_back(0);
	for(int i = 1; i < cz; i+=2)
		y.push_back(0);
	int ts = 0;
	for(int i = 0; i < a.size(); i++) {
		int t = a[i];
		ts += t;
		for(int b = targ; b--;) {
			auto nbt = bt[b+1]|(bt[b]<<t);
			bt[b+1] ^= nbt;
			for(int j = bt[b+1]._Find_first(); j < N*C; j = bt[b+1]._Find_next(j)) {
				p[b+1][j] = i;
			}
			bt[b+1] = nbt;
		}
	}
	vector<int> take(a.size());
	ts/=2;
	while(!bt[targ][ts]) ts++;
	while(targ) {
		x.push_back(a[p[targ][ts]]);
		take[p[targ][ts]] = 1;
		ts -= x.back();
		targ--;
	}
	for(int i = 0; i < take.size(); i++) if(!take[i])
		y.push_back(a[i]);
	sort(all(x));
	sort(all(y));
	reverse(all(y));
	for(auto i : x) cout << i << " "; cout << endl;
	for(auto i : y) cout << i << " "; cout << endl;
}