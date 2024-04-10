#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n;
map<int, int> mp;
int w;
int x;
int cnt;
int q[maxN];

ii pr[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
         mp.clear();
        cin >> n >> w;
        for(int i = 1; i <= n; i++){
            cin >> x;
            q[i] = 0;
            mp[x] ++;
        }
        cnt = 0;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            pr[++cnt].fi = itr->fi;
            pr[cnt].se = itr->se;
            
        }
        reverse(pr + 1, pr + cnt + 1);
        int ans = 0;
        int summer = 0;
        for(int i = 1; i <= cnt; i++){
            summer += pr[i].se;
        }
        while(summer > 0){
            int sum = 0;
            for(int i = 1; i <= cnt; i++){
                while(pr[i].se > 0 && pr[i].fi + sum <= w){
                    sum += pr[i].fi;
                    summer--;
                    pr[i].se--;
                }
            }
            ans++;
        }
        
        cout << ans << endl;
    }
}