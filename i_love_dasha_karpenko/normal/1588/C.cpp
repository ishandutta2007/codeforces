//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 3e5+7;
ll pr[N][2];
void solve(){
    int n;
    cin>>n;
    ll sum[2] = {0,0};
    set<pair<ll,int> > pref[2];
    map<ll,int> cnt_beg[2];
    for(int c = 0;c<2;++c){
        pref[c].insert({0,0});
        cnt_beg[c][0]++;
    }
    ll res = 0;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        sum[i&1]+=val;
        sum[!(i&1)]-=val;

        while(!pref[i&1].empty()){
            auto [val,pos] = *pref[i&1].rbegin();
            if (val<=sum[i&1])
                break;
            cnt_beg[0][pr[pos][0]]--;
            cnt_beg[1][pr[pos][1]]--;
            pref[0].erase({pr[pos][0],pos});
            pref[1].erase({pr[pos][1],pos});
        }
        res+=cnt_beg[i&1][sum[i&1]];
        for(int c = 0;c<2;++c){
            pr[i][c] = sum[c];
            pref[c].insert({pr[i][c],i});
            cnt_beg[c][pr[i][c]]++;
        }
    }
    cout<<res<<endl;


}
signed main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}