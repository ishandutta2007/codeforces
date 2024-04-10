//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 1e5+7;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> su,cnt,pos;
    for(int i = 1;i<=n;i+=1){
        ll pref = 0,sum = 0;
        for(int i = 1;i<=m;i+=1){
            int val;
            cin>>val;
            pref += val;
            sum += pref;
        }
        bool flag = 0;
        for(int i = 0;i<su.size();i+=1){
            if (su[i]==sum){
                cnt[i] += 1;
                flag = 1;
                break;
            }
        }
        if (!flag){
            su.push_back(sum);
            cnt.push_back(1);
            pos.push_back(i);
        }
    }
    int big = 0;
    if (cnt[big]!=1){
        big += 1;
    }
    cout<<pos[big]<<' '<<su[1-big]-su[big]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}