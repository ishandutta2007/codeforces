#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM],last[DIM],nxt[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll prev[] = {0,0};
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(ll i = n;i>=1;--i){
        nxt[i] = last[A[i]];
        if (last[A[i]]==0)nxt[i] = INF;
        last[A[i]] = i;
    }
    ll res = n;
    ll nx[] = {INF,INF};
    nxt[0] = INF;
    for(ll i = 1;i<=n;++i){
        if (i==nx[0]){
            --res;
            nx[0] = nxt[i];
        }
        else if (i==nx[1]){
            --res;
            nx[1] = nxt[i];
        }
        else{
            if (nx[0]>nx[1])nx[0] = nxt[i];
            else nx[1] = nxt[i];
        }
    }
    cout<<res<<endl;
    return 0;
}