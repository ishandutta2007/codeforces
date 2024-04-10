// Hydro submission #62c6ce2ac3a9fda5622b166b@1657196075189
/////////////////////include/////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stdio.h>
#include <climits>
using namespace std;
/////////////////////define/////////////////////
#define ci(x) if(x) cout << "YES" << endl; else cout << "NO" << endl;
#define cii(x) if(check(x))
#define MOD 1000000007
#define MOD2 998244353
#define oo 1e9
#define ool 1e18
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define alll(x) (x), (x) + n
#define clr(x) (x).clear();
#define fri(x) for(int i = 0; i < x; i++)
#define frj(x) for(int j = 0; j < x; j++)
#define frr(a, b) for(int i = a; i < b; i++)
#define fra(x) for(int i = 0; i < x; i++) cin >> a[i];
#define frb(x) for(int i = 0; i < x; i++) cin >> b[i];
#define frs(x) for(auto it = x.begin(); it != x.end(); ++it)
#define fr(x) for(auto it : x)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define dbg(x) cerr << #x << ": " << x << endl;
#define ce(x) cout << x << endl;
#define uniq(x) x.resize(unique(all(x)) - x.begin()); //make all one after sorting
#define blt __builtin_popcount
/////////////////////print array, vector, deque, set, multiset, pair, map ///////////////////// 
template <class T> void print(T t) {cerr << t;}
template <class T> void print(T v[], int n) {cerr << "["; for(int i = 0; i < n; i++) {print(v[i]); cerr << " "; } cerr << "]" << endl;}
template <class T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]" << endl;}
template <class T> void print(deque<T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]" << endl;}
template <class T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]" << endl;}
template <class T> void print(multiset <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]" << endl;}
template <class T, class V> void print(pair <T, V> p) {cerr << "{"; print(p.first); cerr << ","; print(p.second); cerr << "}" << endl;}
template <class T, class V> void print(map <T, V> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]" << endl;}
/////////////////////code/////////////////////
int pref[200005][205]; vi pos[205];
int solve() {
    int a, n, sz, j, c, cf, l, r, y, ans = 0; 
    cin >> n;
    fri(201) pos[i].clear();
    for(j = 1; j <= n; j++) {
        cin >> a;
        frr(1, 201) pref[j][i] = pref[j - 1][i];
        pref[j][a]++;
        pos[a].pb(j);
    }
    for(c = 0; c < 201; c++) {
        sz = pos[c].size();
        frr(1, sz / 2 + 1) {
            l = pos[c][i - 1] + 1;
            r = pos[c][sz - i] - 1;
            y = 0;
            for(cf = 0; cf < 201; cf++) 
                y = max(y, pref[r][cf] - pref[l - 1][cf]);
            ans = max(ans, 2 * i + y);
        }
    }
    fri(201) ans = max(ans, pref[n][i]);
    return ans;
}
int main() {
    fastio;
    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}