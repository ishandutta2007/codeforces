#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll gridN = 1000;
const ll mod = 1000000007;
ll N,M,R,B[2001],X[2001],Y[2001], A[2001][2001],S[2001][2001], C[2001],nck[2001][2001];
ll cntp(ll sx, ll sy, ll ex, ll ey){
    if(sx>ex||sy>ey)
        return 0;
    return S[ex][ey]-S[sx-1][ey]-S[ex][sy-1]+S[sx-1][sy-1];
}
ll inin(ll a, ll b){
    ll sx = max(1ll,max(X[a], X[b])-R), sy = max(1ll,max(Y[a],Y[b])-R);
    ll ex = min(1000ll,min(X[a], X[b])+R), ey = min(1000ll,min(Y[a],Y[b])+R);
    return cntp(sx, sy, ex, ey);
}
ll inout(ll a, ll b){
    return C[a]-inin(a,b);
}
ll sum(ll a, ll b){
    return (a+b)%mod; 
}
ll sub(ll a, ll b){
    return (a-b+mod)%mod;
}
ll mul(ll a,ll b){
    return a*b%mod;
}
ll NCK(ll a, ll b){
    if(b>a||b<0||a<0){
        return 0;
    }
    return nck[a][b];
}
void solve(){
    cin>>N>>M>>R;
    for(ll i=1 ; i<=N ; i++){
        cin>>X[i]>>Y[i]>>B[i];
        A[X[i]][Y[i]] = 1;
    }
    S[1][1] = A[1][1];
    for(ll i=2 ; i<=1000 ; i++){
        S[1][i] = sum(A[1][i],S[1][i-1]);
        S[i][1] = sum(A[i][1],S[i-1][1]);
    }
    for(ll i=2 ; i<=1000 ; i++){
        for(ll j=2 ; j<=1000 ; j++){
            S[i][j] = sum(sub(sum(S[i-1][j], S[i][j-1]), S[i-1][j-1]), A[i][j]);
        }
    }
    for(ll i=1 ; i<=N ; i++){
        for(ll j=1 ; j<=N ; j++){
            if(max(abs(X[i]-X[j]),abs(Y[i]-Y[j]))<=R){
                C[j]++;
            }
        }
    }
    for(ll i=0 ; i<=N ; i++){
        nck[i][0] = 1ll;
    }
    for(ll i=1 ; i<=N ; i++){
        for(ll j=1 ; j<=i ; j++){
            nck[i][j] = sum(nck[i-1][j],nck[i-1][j-1]);
        }
    }
    ll ans = 0;
    for(ll i=1 ; i<=N ; i++){
        for(ll j=i+1 ; j<=N ; j++){
            ll a = inin(i,j);
            ll b = inout(i,j);
            ll c = inout(j,i);
            //cout<<a<<" "<<b<<" "<<c<<"\n";
            //cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<c<<"\n";
            ans = sum(ans,mul(2*B[i],mul(B[j],(NCK(N,M)-NCK(N-a-b,M)-NCK(N-a-c,M)+NCK(N-a-b-c,M))%mod)));
        }
    }
    //cout<<ans<<"\n";
    for(ll i=1 ; i<=N ; i++){
        //cout<<C[i]<<"\n";
        ans = sum(ans,mul(mul(sub(NCK(N,M),NCK(N-C[i],M)),B[i]),B[i]));
    }
    cout<<(ans+mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}