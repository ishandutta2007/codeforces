//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'a')
const int N = 2e5+7;
int ans[N];
pair<int,int> val[N];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int> > V[2];
    ll sum[2] = {0,0};
    vector<pair<pair<int,int>,int> > bal;
    for(int i = 1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        val[i] = {a,b};
        int nl = max(a-m,0),nr = max(b-m,0);
        int l = nl-(b-(m-(a-nl))),r = (a-(m-(b-nr))) - nr;
        if (l>0 && r>0){
            V[0].push_back({{l,r},i});
            sum[0]+=l;
            ans[i] = l;
        }
        else if (l<0 && r<0){
            l = -l;
            r = -r;
            swap(l,r);
            V[1].push_back({{l,r},i});
            sum[1]+=l;
            ans[i] = -l;
        }
        else{
            bal.push_back({{l,r},i});
        }
    }
    int t;
    ll dif;
    if (sum[0]<sum[1])
        t = 0,dif = sum[1]-sum[0];
    else t = 1,dif = sum[0]-sum[1];
    for(auto [bnd,pos]:V[t]){
        ll g = min(ll(bnd.second-bnd.first),dif);
        if (g&1)
            --g;
        dif-=g;
        if (t==0)
            ans[pos]+=g;
        else ans[pos]-=g;
    }
    if (t==0)
        dif = -dif;
    for(auto [bnd,pos]:bal){
        if (dif<0){
            ll g = min(ll(bnd.second),-dif);
            if ((g-bnd.first)&1)
                --g;
            dif+=g;
            ans[pos]+=g;
        }
        else{
            ll g = min(-ll(bnd.first),dif);
            if ((g-bnd.first)&1)
                --g;
            dif-=g;
            ans[pos]-=g;
        }
    }
    cout<<abs(dif)<<endl;
    for(int i = 1;i<=n;++i){
        auto [a,b] = val[i];
        int cur = a-b;
        int dif = ans[i]-cur;
        if (dif>0)
            b-=dif;
        else a+=dif;
        int left = (m-abs(dif))>>1;
        a-=left;
        b-=left;
        cout<<val[i].first-a<<' '<<val[i].second-b<<endl;
        ans[i] = 0;
    }
    cout<<endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();

    return 0;
}