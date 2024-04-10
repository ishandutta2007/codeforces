//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2007;
ll vis[DIM],n;
ll get(){
    vector<ll> v[2];
    for(ll i = 1;i<=n;++i){
        if (vis[i]==0)continue;
        v[vis[i]-1].push_back(i);
    }
    cout<<"? "<<v[0].size()<<' '<<v[1].size()<<endl;
    for(ll i = 0;i<2;++i) {
        for (ll to:v[i])cout << to << ' ';
        cout << endl;
    }
    ll ret;
    cin>>ret;
    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i = 1;i<=n;++i){
            vis[i] = 1;
        }
        vector<ll> V;
        vector<ll> ans;
        ll pos = 0,cnt1 = 0,cnt2 = 0;
        ll dif = 0;
        for(ll i = 1;i<n;++i){
            vis[i] = 2;
            ll val = get();
            if (val==0){
                vis[i] = 0;
                if (pos==0)
                    V.push_back(i);
                else
                    ans.push_back(i);
            }
            else if (pos==0){
                pos = i;
                //++cnt1;
                dif = val;
                for(ll j = 1;j<=n;++j)vis[j] = 0;
                vis[i] = 1;
            }
            else {
                vis[i] = 0;
                if (val>0)++cnt1;
                else ++cnt2;
            }
        }
        if (cnt1-cnt2==dif)ans.push_back(n);
        for(ll i = 1;i<=n;++i)
            vis[i] = 0;
        vis[pos] = 2;
        for(ll to:V)
            vis[to] = 1;
        if (!V.empty()) {

            for (ll to:V)
                vis[to] = 0;
            ll l = -1, r = V.size();
            while (l != r) {
                if (l>=V.size()-1)break;
                ll tm = (l + r + 1) / 2;
                for (ll i = 0; i <= tm; ++i) {
                        if (i<V.size())
                        vis[V[i]] = 1;
                }
                if (get())
                    r = tm-1;
                else l = tm;
                for (ll to:V)
                    vis[to] = 0;
            }
            if (l+1!=V.size())
                vis[V[l+1]] = 1;
        }
        else
            for(ll to:V)
                vis[to] = 0;

        for(ll to:V){
            if (vis[to]==0)ans.push_back(to);
        }
        cout<<"! "<<ans.size()<<' ';
        for(ll to:ans)
            cout<<to<<' ';
        cout<<endl;


    }

    return 0;
}