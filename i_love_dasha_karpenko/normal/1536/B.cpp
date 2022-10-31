//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1007;
ll A[DIM];
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll MOD = 1E9+123;
const ll base = 31;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'a'+1;
        }
        set<upp> S;
        for(ll i = 1;i<=n;++i){
            upp cur = {0,0};
            for(ll j = i;j<=n;++j){
                cur.first = cur.first*base+A[j];
                cur.second = (cur.second*base+A[j])%MOD;
                S.insert(cur);
            }
        }
        ll len = n+2;
        vector<pair<ll,ll> > V;
        for(ll i = 1;i<=n;++i){
            upp cur = {0,0};
            for(ll j = i;j<=n;++j){
                if (j-i+2>len)
                    break;
                cur.first = cur.first*base+A[j];
                cur.second = (cur.second*base+A[j])%MOD;
                for(ll nxt = 1;nxt<=26;++nxt){
                    upp ncur = cur;
                    ncur.first = ncur.first*base+nxt;
                    ncur.second = (ncur.second*base+nxt)%MOD;
                    if (S.count(ncur)==0){
                        if (j-i+2<len)V.clear(),len = j-i+2;
                        V.push_back({i,nxt});
                    }
                }
            }
        }
        upp cur = {0,0};
        for(ll nxt = 1;nxt<=26;++nxt){
            upp ncur = cur;
            ncur.first = ncur.first*base+nxt;
            ncur.second = (ncur.second*base+nxt)%MOD;
            if (S.count(ncur)==0){
                if (1<len)
                    V.clear(),len = 1;
                V.push_back({0,nxt});
            }
        }
        vector<string> ans;
        for(auto [st,last]:V){
            string s = "";
            for(ll i = st;i<st+len-1;++i)
                s+=char(A[i]-1+'a');
            s+=char(last-1+'a');
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<endl;
    }
    return 0;
}