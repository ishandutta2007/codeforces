#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM],depth[DIM],n;
ll F(ll x){
    ll ptr = 2;
    for(ll i = 1;i<=n;++i)depth[i] = 0;
    depth[1] = 0;
    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()){
        ll t = Q.front();
        Q.pop();
        if (depth[t]+1>x)continue;
        if (ptr>n)continue;
        Q.push(ptr);
        depth[ptr] = depth[t]+1;
        ++ptr;
        while(ptr<=n && A[ptr]>A[ptr-1]){
            Q.push(ptr);
            depth[ptr] = depth[t]+1;
            ++ptr;
        }
    }
    if (ptr<=n)return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        ll l = 1,r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            if (F(tm))r = tm;
            else l = tm+1;
        }
        cout<<l<<endl;
    }
    return 0;

}