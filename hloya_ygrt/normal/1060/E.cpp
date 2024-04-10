// hloya template v25
  
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<int> g[maxn];
ll ds[maxn][2], dk[maxn][2];
ll us[maxn][2], uk[maxn][2];

void dfs(int v, int p = -1) {
	ds[v][0] = ds[v][1] = dk[v][0] = dk[v][1] = 0;

	for (int to : g[v]) {
		if (p != to) {
			dfs(to, v);

			for (int p = 0; p < 2; p++) {
				dk[v][p] += dk[to][1 ^ p];
				ds[v][p] += ds[to][1 ^ p] + dk[to][1 ^ p];
			}

			ds[v][1] += 1;
			dk[v][1] += 1;
		}
	}
	// cout << v << ' ' << ds[v][0] << ' ' << ds[v][1] << endl;
}

void dfs2(int v, int p = -1) {
	// cout << v << ' ' << us[v][0] << ' ' << us[v][1] << endl;
	vector<ll> k(2, 0), s(2, 0);
	for (int i = 0; i < g[v].size(); i++) {
		if (g[v][i] != p) {
			int to = g[v][i];

			for (int p = 0; p < 2; p++) {
				uk[to][p] += k[1 ^ p];
				us[to][p] += s[1 ^ p] + k[1 ^ p];
			}

			for (int p = 0; p < 2; p++) {
				k[p] += dk[to][1 ^ p];
				s[p] += ds[to][1 ^ p] + dk[to][1 ^ p];
			}
			s[1] += 1;
			k[1] += 1;
		}
	}

	k.assign(2, 0);
	s.assign(2, 0);
	for (int i = (int)g[v].size() - 1; i >= 0; i--) {
		if (g[v][i] != p) {
			int to = g[v][i];

			for (int p = 0; p < 2; p++) {
				uk[to][p] += k[1 ^ p];
				us[to][p] += s[1 ^ p] + k[1 ^ p];
			}

			for (int p = 0; p < 2; p++) {
				k[p] += dk[to][1 ^ p];
				s[p] += ds[to][1 ^ p] + dk[to][1 ^ p];;
			}
			s[1] += 1;
			k[1] += 1;

			for (int p = 0; p < 2; p++) {
				uk[to][p] += uk[v][1 ^ p];
				us[to][p] += us[v][1 ^ p] + uk[v][1 ^ p];
			}
			us[to][1] += 1;
			uk[to][1] += 1;

			dfs2(to, v);
		}
	}
}

int main() {
	int n;
	// freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;

		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(0);
	dfs2(0);

	ll ans = 0;
	for (int v = 0; v < n; v++) {
		assert((ds[v][0] + us[v][0]) % 2 == 0);
		assert((ds[v][1] + us[v][1] + uk[v][1] + dk[v][1]) % 2 == 0);
		ans += (ds[v][0] + us[v][0]) / 2ll;
		ans += (ds[v][1] + us[v][1] + uk[v][1] + dk[v][1]) / 2ll;
	}
	cout << ans / 2 << "\n";
	return 0;
}