#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E18;
ll A[DIM],val[DIM];
pair<ll,ll> pref[DIM],suf[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            if (ch=='+')A[i] = 1;
            else A[i] = -1;
        }
        ll cur = 0;
        for(ll i = 1;i<=n;++i){
            pref[i] = pref[i-1];
            cur+=A[i];
            val[i] = cur;
            pref[i].first = min(pref[i].first,cur);
            pref[i].second = max(pref[i].second,cur);
        }
        cur = 0;
        for(ll i = n;i>=1;--i){
            suf[i] = suf[i+1];

            suf[i].first +=A[i];
            suf[i].second +=A[i];
            suf[i].first = min(suf[i].first,A[i]);
            suf[i].second = max(suf[i].second,A[i]);
        }
        for(ll i = 1;i<=m;++i){
            ll tl,tr;
            cin>>tl>>tr;
            pair<ll,ll> p1 = pref[tl-1];
            pair<ll,ll> p2 = suf[tr+1];
            p2.first+=val[tl-1];
            p2.second+=val[tl-1];
            p1.first=min(p1.first,p2.first);
            p1.second=max(p1.second,p2.second);
            cout<<p1.second-p1.first+1<<endl;
        }
        for(ll i = 1;i<=n;++i){
            pref[i] = suf[i]= {0,0};
            val[i] = 0;
        }
    }
    return 0;
}