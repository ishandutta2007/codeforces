#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
ll MOD = 998244353;
ll T,N,M,L,R,G,P,D;
ll fexp(ll b, ll e){
    ll res = 1; b%=MOD;
    for(ll i = 0; i<62;i++){
        if(e&(1LL<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}
ll inv(ll a){
    return fexp(a,MOD-2);
}
ll solve(ll cos){
    if(cos%2==1)return fexp(P+D,cos);
    return (fexp(P+D,cos) + (long long)(D!=P))*inv(2LL) %MOD;
}
int main(){
    cin >> N >> M >> L >> R;
    G = N*M;
    P = (R-L+1)/2;
    D = R-L+1-P;
    if(P < D)swap(P,D);
    if(D == 0){
        cout << "1";
        return 0;
    }
    cout << solve(G);
    return 0;
}