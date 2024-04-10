#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll n,k,A[DIM],cur[DIM];
ll S(ll len,ll div){
    if (div>len)return S(len,div-1);
    ll sum = 0;
    ll avg = len/div;
    ll extra = len%div;
    sum+=extra*(avg+1)*(avg+1);
    div-=extra;
    sum+=div*avg*avg;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n>>k;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        cur[i] = 1;
    }
    k-=n;
    priority_queue<pair<ll,ll> > Q;
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        res+=S(A[i],cur[i]);
        Q.push({S(A[i],cur[i])-S(A[i],cur[i]+1),i});
    }
    while(k){
        --k;
        res-=Q.top().first;
        ll pos = Q.top().second;
        Q.pop();
        cur[pos]++;
        Q.push({S(A[pos],cur[pos])-S(A[pos],cur[pos]+1),pos});
    }
    cout<<res<<endl;
    return 0;
}