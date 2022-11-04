#include<bits/stdc++.h>
#define inf 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    map<int, int> am;
    multiset<array<int, 3>> to_add;
    vi ans(n);
    vi mn(n);
    int globmn = inf;
    for(int i = 0; i < n; i++) {
        while(!to_add.empty() && (*(to_add.begin()))[0] <= a[i].first) {
            auto p = *(to_add.begin());
            to_add.erase(to_add.begin());
            am[p[1]] = (am[p[1]] + p[2]) % mod;
        }
        int var1 = a[i].first - a[i].second;
        int am1 = 1;
        int var2 = inf;
        int am2 = 0;
        if(!am.empty()) {
            auto it = am.begin();
            var2 = it->first;
            am2 = it->second;
            var2 += a[i].first;
            var2 -= a[i].second;
        }
        int here = 0;
        if(var1 <= var2) {
            to_add.insert({a[i].second, var1, am1});
            here = (here + am1) % mod;
        }
        if(var2 <= var1) {
            to_add.insert({a[i].second, var2, am2});
            here = (here + am2) % mod;
        }
        ans[i] = here;
        mn[i] = min(var1, var2) + a[i].second;
        //cout << a[i].first << ' ' << a[i].second << ' ' << ans[i] << ' ' << mn[i] << endl;
    }
    int maxl = a[a.size() - 1].first;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].second > maxl) {
            globmn = min(globmn, mn[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i].second > maxl && mn[i] == globmn) {
            res = (res + ans[i]) % mod;
        }
    }
    cout << res;

}