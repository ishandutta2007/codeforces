#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int last[300005];
int first[300005];
int dp[300005];
int niz[300005];

map <int, int> u;

void solve(){
    u.clear();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        last[i] = n;
        first[i] = 0;
    }
    vector <int> vec;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        vec.push_back(niz[i]);
    }
    int cnt = 0;
    sort(vec.begin(), vec.end());
    for(auto c : vec){
        if(!u[c]) u[c] = ++cnt;
    }
    for(int i=1; i<=n; i++){
        int x = u[niz[i]];
        if(!first[x]) first[x] = i;
        last[x] = i;
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        if(last[i-1] < first[i]) dp[i] = dp[i-1] + 1;
        res = max(res, dp[i]);
    }
    cout << cnt-res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}