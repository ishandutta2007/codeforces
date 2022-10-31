#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#define endl '\n'
#endif
 
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
 
ll pwr(ll a,ll b){
	a %= mod;
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
const int N = 2e5 + 5;
int a[N], r[N], c[N], b[N];
 
map<int,int> mm;
vector<int> v[N];
int im[N];
int n, m, k, q;
 
int dp[2][N];
 
int shortest_path(int x1,int y1,int x2,int y2) {
	if(x1 == x2)
		return abs(y2 - y1);
	assert(x1 <= x2);
	int idx = lower_bound(b + 1, b + q + 1, y1) - b;
	int ans = 1e18;
	if(idx <= q) {
		ans = min(ans, abs(y1 - b[idx]) + abs(y2 - b[idx]) + x2 - x1);
	}
	idx--;
	if(idx >= 1) {
		ans = min(ans, abs(y1 - b[idx]) + abs(y2 - b[idx]) + x2 - x1);
	}
	debug(x1, y1, x2, y2, ans);
	return ans;
}
 
void solve(){
	cin >> n >> m >> k >> q;
	fr(i, 1, k) {
		cin >> r[i] >> c[i];
		mm[r[i]] = 0;
	}
	int cc = 0;
	for(auto &it : mm) {
		it.se = ++cc;
		im[cc] = it.fi;
	}
	fr(i, 1, k) {
		v[mm[r[i]]].pb(c[i]);
	}
	fr(i, 1, cc) {
		sort(all(v[i]));
	}
	fr(i, 1, q)
		cin >> b[i];
	sort(b + 1, b + q + 1);
	int dd = v[1].back() - v[1][0];
	dp[1][1] = shortest_path(1, 1, im[1], v[1][0]) + dd;
	dp[0][1] = shortest_path(1, 1, im[1], v[1].back()) + dd;
	fr(i, 1, cc - 1) {
		int dd = v[i + 1].back() - v[i + 1][0];
		int d1 = shortest_path(im[i], v[i][0], im[i + 1], v[i + 1].back()) + dd;
		int d2 = shortest_path(im[i], v[i].back(), im[i + 1], v[i + 1].back()) + dd;
		dp[0][i + 1] = min(d1 + dp[0][i], d2 + dp[1][i]);
		d1 = shortest_path(im[i], v[i][0], im[i + 1], v[i + 1][0]) + dd;
		d2 = shortest_path(im[i], v[i].back(), im[i + 1], v[i + 1][0]) + dd;
		dp[1][i + 1] = min(d1 + dp[0][i], d2 + dp[1][i]);
	}
	cout << min(dp[0][cc], dp[1][cc]);
}
signed main(){
    IO;
    #ifdef LOCAL
        freopen("inp.txt","r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    // cin >> t;
    fr(tt, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}