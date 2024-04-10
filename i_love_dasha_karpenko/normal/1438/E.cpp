#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E18;
ll A[DIM],last[DIM],pref[DIM],L[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll,ll> > V;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        while(!V.empty() && V.back().first<=A[i])V.pop_back();
        if (V.empty())last[i] = -1;
        else{
            auto it = lower_bound(V.rbegin(),V.rend(),pair<ll,ll>{A[i],-INF});
            if (it==V.rend())last[i] = -1;
            else
            last[i] = it->second;
        }
        V.push_back({A[i],i});
        pref[i] = pref[i-1]+A[i];
        L[i] = lower_bound(pref,pref+i,pref[i-1]-A[i])-pref+1;
        L[i] = min(L[i],i-2);
        L[i] = max(L[i],1ll);
        //cout<<last[i]<<' ';
    }
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        ll ptr = i-2;
        for(ll j = i-2;j>=1 && A[j]<A[i];--j){
            ptr = min(ptr,j-1);
            if (i-j+1>=3 && pref[i-1]-pref[j]==(A[j]^A[i]))++res;
        }

        if (ptr>0 && i-ptr+1>=3 && pref[i-1]-pref[ptr]==(A[ptr]^A[i]))++res;
        --ptr;
        while(ptr>0){
            if (i-ptr+1>=3 && pref[i-1]-pref[ptr]==(A[ptr]^A[i]))++res;
            ptr = last[ptr];
        }
    }
    cout<<res<<endl;
    return 0;
}