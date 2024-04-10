#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll MOD = 10e9+123;
const ll INF = 10E16;
const ll base = 31;
ll gi(char ch){
    return ch-'0';
}
upp cnthash(string &s){
    upp ret = {0,0};
    for(ll i = 0;i<s.length();i++){
        ret.fi = ret.fi*base+gi(s[i])+1;
        ret.sc = (ret.sc*base+gi(s[i])+1)%MOD;
    }
    return ret;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        //cout<<0<<endl;
        //continue;
        ll cnt[2][2];
        cnt[0][0]=cnt[1][1]=cnt[1][0]=cnt[0][1] = 0;
        vector<pair<upp,ll> > V[2];
        vector<upp> v[2];
        ll n; cin>>n;
        forn(i,n){
            string s;
            cin>>s;
            ll s1 = gi(s[0]),s2 = gi(s[s.length()-1]);
            if (s1+s2==1){
                if (s1==0){
                    V[s1].pb({cnthash(s),i});
                    v[s1].pb(cnthash(s));
                }
                else{
                    reverse(s.begin(),s.end());
                    V[s1].pb({cnthash(s),i});
                    v[s1].pb(cnthash(s));
                }
            }
            else{
                cnt[s1][s2]++;
            }
        }
        sort(V[0].begin(),V[0].end());
        sort(V[1].begin(),V[1].end());
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        vector<ll> av[2];
        for(ll i = 0;i<V[0].size();i++){
            auto it = lower_bound(v[1].begin(),v[1].end(),V[0][i].fi);
            if (it==v[1].end()){
                cnt[0][1]++;
                av[0].pb(V[0][i].sc);
            }
            else{
                upp g = *it;
                if (g!=V[0][i].fi){
                    cnt[0][1]++;
                    av[0].pb(V[0][i].sc);
                }
            }
        }
        for(ll i = 0;i<V[1].size();i++){
            auto it = lower_bound(v[0].begin(),v[0].end(),V[1][i].fi);
            if (it==v[0].end() ){
                cnt[1][0]++;
                av[1].pb(V[1][i].sc);
            }
            else{
                upp g = *it;
                if (g!=V[1][i].fi){
                    cnt[1][0]++;
                    av[1].pb(V[1][i].sc);
                }
            }
        }
        //if (cnt[0][1]-cnt[1][0]!=V[0].size()-V[1].size())n/=0;
        ll res = INF;
        vector<ll> ans;
        if (cnt[1][1]*cnt[0][0]>0 && V[1].size()+V[0].size()==0){
            cout<<-1<<endl;
            continue;
        }
        //cout<<V[1].size()<<' '<<V[0].size()<<' '<<cnt[0][0]<<' '<<<<endl;
        if (1){
            ll r = abs(cnt[1][0]-cnt[0][1]);
            if (r%2==0 && res>r/2){
                ans.clear();
                r/=2;
                res=r;
                if (cnt[0][1]>cnt[1][0]){
                    for(ll i = 0;i<r;i++){
                        ans.pb(av[0][i]);
                    }
                }
                else{
                    for(ll i = 0;i<r;i++){
                        ans.pb(av[1][i]);
                    }
                }
            }
        }
        ll r = abs(cnt[1][0]-cnt[0][1]);
        r--;
        if (r%2==0 && res>r/2){
            ans.clear();
            r/=2;
            res=r;
            if (cnt[0][1]>cnt[1][0]){
                for(ll i = 0;i<r;i++){
                    ans.pb(av[0][i]);
                }
            }
            else{
                for(ll i = 0;i<r;i++){
                    ans.pb(av[1][i]);
                }
            }
        }
        if (res==INF)cout<<-1<<endl;
        else{
            cout<<ans.size()<<endl;
            for(ll to:ans)cout<<to<<' ';
            cout<<endl;
        }
    }
    return 0;
}