#include <bits/stdc++.h>
using namespace std;
#define DIM 200007
typedef long long ll;
typedef pair<ll,ll> pll;
#define fi first
#define sc second
const ll mod = pow(10,9);
struct node{
    ll fi,sc,pos;
};
ll n,fen[DIM],ans[DIM];
node A[DIM];
ll A1[DIM];
queue<ll> Q;
void add(ll pos,ll delta){
    for(ll i = pos;i<=n;i+=(i&-i))
        fen[i]+=delta;
}
ll cn(ll pos){
    ll res= 0;
    for(ll i = pos;i>0;i-=(i&-i))
        res+=fen[i];
    return res;
}
bool mc(node a,node b){
return a.fi<b.fi;
}
int main()
{
    cin>>n;
    for (ll i = 1;i<=n;i++){
        cin>>A[i].fi>>A[i].sc;
        A[i].fi+=mod;
        A[i].sc+=mod;
        A[i].pos= i;
        A1[i] = A[i].sc;
    }
    sort(A+1,A+1+n,mc);
    sort(A1+1,A1+n+1);
    for(ll i = 1;i<=n;i++){
        auto it = lower_bound(A1+1,A1+n+1,A[i].sc);
        ll poz= it-A1;
        add(poz,1);
    }
    for(ll i = 1;i<=n;i++){
        auto it = lower_bound(A1+1,A1+n+1,A[i].sc);
        ll poz= it-A1;
        ans[A[i].pos] = cn(poz)-1;
        add(poz,-1);
    }
    for(ll i = 1;i<=n;i++)cout<<ans[i]<<endl;
}
/*
3
-999999997 999999997
-999999998 999999998
-999999999 999999999
*/