#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
const int N = 100005;
int a[N];
int minCost[N];
int grp[N];
unordered_map<string, int> pos;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        pos[s] = i;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        int cst = 1e9+10;
        for(int j = 1; j <= x; j++){
            int r;
            cin >> r;
            grp[r] = i;
            cst = min(cst, a[r]);
        }
        minCost[i] = cst;
    }
    long long ans = 0;
    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        ans += minCost[grp[pos[s]]];
        // cerr << s << " " << pos[s] << " " << grp[pos[s]] << " " << ans << endl;
    }
    cout << ans;
}