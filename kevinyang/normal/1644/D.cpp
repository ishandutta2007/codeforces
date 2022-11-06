#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int modpow(int x, int y) {
    return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m,k,q;
        cin >> n >> m >> k >> q;
        vector<pair<int,int>>arr(q+1);
        for(int i = 1; i<=q; i++){
            int x,y;
            cin >> x >> y;
            arr[i] = {x,y};
        }
        map<int,int>row;
        map<int,int>col;
        int cntr = 0; int cntc = 0;
        int cnt = 0;
        for(int i = q; i>=1; i--){
            if(cntr==n||cntc==m){
                break;
            }
            if(row[arr[i].first]&&col[arr[i].second]){
                continue;
            }
            cnt++;
            if(row[arr[i].first]==0)cntr++;
            row[arr[i].first] = 1;
            if(col[arr[i].second]==0)cntc++;
            col[arr[i].second] = 1;
        }
        cout << modpow(k,cnt) << "\n";
    }
    return 0;
}