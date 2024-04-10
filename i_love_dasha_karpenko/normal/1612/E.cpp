//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 2e5+7;
const int MXK = 20;
vector<int> cnt[N];
ll su[N];
#define ratio ddsfds
struct ratio{
    ll a,b;
    ratio (ll a1 = 0,ll b1 = 1){
        a = a1;
        b = b1;
        ll g = __gcd(a,b);
        a/=g;
        b/=g;
    }
};
const bool operator <(ratio a,ratio b){
    return a.a*b.b<a.b*b.a;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        int m,k;
        cin>>m>>k;
        cnt[m].push_back(k);
        su[m]+=k;
    }
    for(int i = 0;i<N;++i)
        sort(all(cnt[i]));
    ratio res;
    int clk = 0;
    for(int v = 1;v<=MXK;++v){
        vector<ll> V;
        for(int i = 0;i<N;++i){
            ll sum = 0;
            for(int k:cnt[i]){
                if (k>=v)
                    sum+=v;
                else sum+=k;
            }
            V.push_back(sum);
        }
        sort(all(V),greater<int>());
        ratio r;
        ll sum = 0;
        for(int i = 0;i<v;++i){
            sum+=V[i];
        }
        r = ratio(sum,v);
        if (res<r){
            res = r;
            clk = v;
        }
    }
    vector<pair<ll,int> > V;
    for(int i = 0;i<N;++i)
        V.push_back({su[i],i});
    sort(all(V),greater<pair<ll,int>>());
    ll sum = 0;
    for(int i = 0;i<N;++i){
        sum+=V[i].first;
        if (i>=MXK) {
            ratio r = ratio(sum, i + 1);
            if (res<r){
                res = r;
                clk = i+1;
            }
        }
    }
    vector<int> ans;
    if (clk<=MXK){
        int v = clk;
        vector<pair<ll,int> > V;
        for(int i = 0;i<N;++i){
            ll sum = 0;
            for(int k:cnt[i]){
                if (k>=v)
                    sum+=v;
                else sum+=k;
            }
            V.push_back({sum,i});
        }
        sort(all(V),greater<pair<ll,int> >());
        ratio r;
        ll sum = 0;
        for(int i = 0;i<v;++i){
            sum+=V[i].first;
            ans.push_back(V[i].second);
        }
    }
    else{
        for(int i = 0;i<clk;++i)
            ans.push_back(V[i].second);
    }
    cout<<ans.size()<<endl;
    for(int to:ans)
        cout<<to<<' ';
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}