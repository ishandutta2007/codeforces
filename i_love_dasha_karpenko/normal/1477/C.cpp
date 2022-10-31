#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
pair<ll,ll> A[DIM];
ll P[DIM];
ll dist(pair<ll,ll> a,pair<ll,ll> b){
    ll d1 = a.first-b.first;
    ll d2 = a.second-b.second;
    return d1*d1+d2*d2;
}
ll F(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    return dist(a,b)+dist(b,c)>dist(a,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
        P[i] = i;
    }
    vector<ll> V;
    ll ptr = 1;
    while(V.size()!=n){
        if (V.size()<2){
            V.push_back(ptr++);
            continue;
        }
        ll pos = -1;
        for(ll i = 0;i<=V.size();++i){
            ll flag = 0;
            if (i>=2 && !F(A[V[i-2]],A[V[i-1]],A[ptr]))flag = 1;
            if (i>=1 && i<V.size() && !F(A[V[i-1]],A[ptr],A[V[i]]))flag = 1;
            if (i>=0 && i+1<V.size() && !F(A[ptr],A[V[i]],A[V[i+1]]))flag = 1;
            if (flag==0){
                pos = i;
                break;
            }
        }
        if (pos==-1){
            cout<<-1<<endl;
            return 0;
        }
        vector<ll> vv;
        for(ll i = 0;i<pos;++i)vv.push_back(V[i]);
        vv.push_back(ptr);
        for(ll i = pos;i<V.size();++i)vv.push_back(V[i]);
        ++ptr;
        V = vv;
    }
    for(ll to:V)cout<<to<<' ';
    cout<<endl;
    return 0;
}