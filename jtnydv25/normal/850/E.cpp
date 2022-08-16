#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define ld double
#define vi vector<int>  
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int mod = 1e9 + 7;
ll powr(ll a, ll b){
	ll x = 1;
	for(; b; b >>= 1, a = (a * 1ll * a) % mod) if(b & 1) x = (x * a) % mod;
	return x;
}
ll inv(ll a, int md){
	return powr(a, md - 2);
}

vi xor_convolution(vi& a, vi& b,int k)// First make size = some power of 2 >= sizes of both.
{
    if(k <= 4)
    {
        vi C(1<<k,0);
        rep(i,0,1<<k)
        rep(j,0,1<<k){
            C[i^j]=(C[i^j]+a[i]*1ll*b[j])%mod;
        }
        return C;
    }
    int inv2 = inv(2,mod);
    vi a1(1<<k);
    vi A(a.begin(),a.begin()+(1<<(k-1))),B(a.begin()+(1<<(k-1)),a.end());
    vi C(b.begin(),b.begin()+(1<<(k-1))),D(b.begin()+(1<<(k-1)),b.end());
    vi X(1<<(k-1)),Y(1<<(k-1)),P(1<<(k-1)),Q(1<<(k-1));
    rep(i,0,1<<(k-1)){
        X[i] = A[i]+B[i],Y[i] = C[i] + D[i];
        if(X[i]>=mod)
            X[i] -= mod;
        if(Y[i]>=mod)
            Y[i]-=mod;
    }
    rep(i,0,1<<(k-1)){
        P[i] = A[i]-B[i],Q[i] = C[i] - D[i];
        if(P[i]<0)
            P[i] += mod;
        if(Q[i]<0)
            Q[i]+=mod;
    }
    vi Z1 = xor_convolution(P,Q,k-1);
    vi Z2 = xor_convolution(X,Y,k-1);
    int hf = 1<<(k-1);
     
    rep(i,0,hf){
        a1[i] = Z1[i]+Z2[i];
        if(a1[i] >= mod)
            a1[i]-=mod;
        a1[i] = (a1[i]*1ll*inv2)%mod;
    }
    rep(i,hf,hf+hf){
        a1[i] = Z2[i-hf]-Z1[i-hf];
        if(a1[i]<0)
            a1[i]+=mod;
        a1[i] = (a1[i]*1ll*inv2)%mod;
    }
    return a1;
}
vi naive_xor_mul(vi& A,vi& B)
{
    int x = max(sz(A),sz(B));
    int _sz = 1,k = 0;
    while(_sz<x)
        _sz<<=1,k++;
 
    A.resize(_sz),
    B.resize(_sz);
    vi C(_sz,0);
    rep(i,0,_sz)
    rep(j,0,_sz)
    C[i^j] = (C[i^j]+A[i]*1ll*B[j])%mod;
    return C;   
}
vi xor_mul(vi& A, vi& B)// xor multiplication of two polynomials.
{
    int x = max(sz(A),sz(B));
    int _sz = 1,k = 0;
    while(_sz<x)
        _sz<<=1,k++;
 
    A.resize(_sz),
    B.resize(_sz);
    return xor_convolution(A,B,k);
}   
vi A, B;
const int N = 2e6 + 12;
int pw2[N];
char s[N];
int main(){
	pw2[0] = 1;
	for(int i = 1; i < N; i++) pw2[i] = (pw2[i - 1] << 1) % mod;
	int n;
	scanf("%d ", &n);
	scanf("%s", s);
	A.resize(1 << n); B.resize(1 << n);
	for(int i = 0; i < (1 << n); i++){
		A[i] = B[i] = s[i] - '0';
	}
	A = xor_mul(A, B);
	int ans = 0;
	
	for(int i = 0; i < (1 << n); i++){
		int k = __builtin_popcount(i);

		ans = (ans + pw2[n - k] * 1ll * A[i]) % mod;
	}
	ans = (ans * 1ll * 3) % mod;
	printf("%d\n", ans);
}