//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s, t;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> t;
	int n = s.size();
	sort(all(s));
	sort(rall(t));
	int i = 0, j = 0, l = 0, r = n-1;
	while(s.size() > (n+1)/2) s.pop_back();
	while(t.size() > n/2) t.pop_back();
	string ans(n, '.');
	for(int a = 0; a < n; a++) {
		if(!(a&1)) {
			if(s[i]<t[j]) {
				ans[l++] = s[i++];
			} else {
				ans[r--] = s.back();
				s.pop_back();
			}
		} else {
			if(s[i]<t[j]) {
				ans[l++] = t[j++];
			} else {
				ans[r--] = t.back();
				t.pop_back();
			}
		}
	}
	cout << ans;
}