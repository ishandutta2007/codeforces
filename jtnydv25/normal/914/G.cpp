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
const int inv2 =(mod + 1) / 2;
vi and_convolution(vi& a, vi& b,int k)// First make size = some power of 2 >= sizes of both.
{
    if(k <= 4)
    {
        vi C(1<<k,0);
        rep(i,0,1<<k)
        rep(j,0,1<<k){
            C[i&j]=(C[i&j]+a[i]*1ll*b[j])%mod;
        }
        return C;
    }
    vi a1(1<<k);
    vi A(a.begin(),a.begin()+(1<<(k-1))),B(a.begin()+(1<<(k-1)),a.end());
    vi C(b.begin(),b.begin()+(1<<(k-1))),D(b.begin()+(1<<(k-1)),b.end());
    vi X(1<<(k-1)),Y(1<<(k-1));
    rep(i,0,1<<(k-1)){
        X[i] = A[i]+B[i],Y[i] = C[i] + D[i];
        if(X[i]>=mod)
            X[i] -= mod;
        if(Y[i]>=mod)
            Y[i]-=mod;
    }
    vi Z = and_convolution(B,D,k-1);
    B = and_convolution(X,Y,k-1);
    int hf = 1<<(k-1);
    
    rep(i,0,hf){
        a1[i] = B[i] - Z[i];
        if(a1[i] < 0)
            a1[i]+=mod;
    }
    rep(i,hf,hf+hf)
    a1[i] = Z[i-hf];
    return a1;
}
vi naive_and_mul(vi& A,vi& B)
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
    C[i&j] = (C[i&j]+A[i]*1ll*B[j])%mod;
    return C;   
}
vi and_mul(vi& A, vi& B)// and multiplication of two polynomials.
{
    int x = max(sz(A),sz(B));
    int _sz = 1,k = 0;
    while(_sz<x)
        _sz<<=1,k++;

    A.resize(_sz),
    B.resize(_sz);
    return and_convolution(A,B,k);
}   

vi or_convolution(vi& a, vi& b,int k)// First make size = some power of 2 >= sizes of both.
{
    if(k <= 4)
    {
        vi C(1<<k,0);
        rep(i,0,1<<k)
        rep(j,0,1<<k){
            C[i|j]=(C[i|j]+a[i]*1ll*b[j])%mod;
        }
        return C;
    }
    vi a1(1<<k);
    vi A(a.begin(),a.begin()+(1<<(k-1))),B(a.begin()+(1<<(k-1)),a.end());
    vi C(b.begin(),b.begin()+(1<<(k-1))),D(b.begin()+(1<<(k-1)),b.end());
    vi X(1<<(k-1)),Y(1<<(k-1));
    rep(i,0,1<<(k-1)){
        X[i] = A[i]+B[i],Y[i] = C[i] + D[i];
        if(X[i]>=mod)
            X[i] -= mod;
        if(Y[i]>=mod)
            Y[i]-=mod;
    }
    vi Z = or_convolution(A,C,k-1);
    B = or_convolution(X,Y,k-1);
    int hf = 1<<(k-1);
    rep(i,0,hf)
    a1[i] = Z[i];
    rep(i,hf,hf+hf){
        a1[i] = B[i-hf] - Z[i-hf];
        if(a1[i] < 0)
            a1[i]+=mod;
    }
    return a1;
}
vi naive_or_mul(vi& A,vi& B)
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
    C[i|j] = (C[i|j]+A[i]*1ll*B[j])%mod;
    return C;   
}
vi or_mul(vi& A, vi& B)// or multiplication of two polynomials.
{
    int x = max(sz(A),sz(B));
    int _sz = 1,k = 0;
    while(_sz<x)
        _sz<<=1,k++;

    A.resize(_sz),
    B.resize(_sz);
    return or_convolution(A,B,k);
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

const int N = 1e6 + 10;
inline int fix(ll x){
	x %= mod;
	if(x < 0) x += mod;
	return x;
}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int add(int x, int y){
	x += y;
	if(x >= mod) x -= mod;
	return x;
}
inline int sub(int x,int y){
	x -= y;
	if(x < 0) x += mod;
	return x;
}

int f[N], s[N], freq[N];
vi A, B, C;
const int MAX = (1 << 17);

void Print(vi & X, int size){
	for(int i = 0; i < size; i++){
		cerr << X[i] << " ";
	} cerr << endl;
}
int main(){
	f[0] = 0; f[1] = 1;
	for(int i = 2; i < N; i++){
		f[i] = (f[i - 1] + f[i - 2]);
		if(f[i] >= mod) f[i] -= mod;
	}
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(s[i]);
		freq[s[i]] ++;
	}
	A.resize(1 << 17);
	for(int i = 1; i <= n; i++){
		A[s[i]]++;
	}
	B = A;
	C.resize(MAX);
	 A = xor_mul(A, B);
	for(int i = 0; i < MAX; i++){
		A[i] = mul(A[i], f[i]);
	}
	B.resize(0);
	B.resize(MAX);
	for(int i = 1; i <= n; i++) B[s[i]] = add(B[s[i]], f[s[i]]);
	A = and_mul(A, B);
	// Print(A, 4);
	for(int i = 0; i < MAX; i++){
		int mask = (MAX - 1) ^ i;
		int cnt = 0;
		for(int submask = mask; submask > 0; submask = (mask & (submask - 1))){
			if(!freq[i] || !freq[submask]) continue;
			int val = mul(mul(freq[i], freq[submask]), f[i | submask]);
			C[i | submask] = add(C[i | submask], val);
		}
		int submask = 0;
		int val = mul(mul(freq[i], freq[submask]), f[i | submask]);
		C[i | submask] = add(C[i | submask], val);
	}
	A = and_mul(A, C);
	int ans = 0;
	for(int i = 0; i < 17; i++) ans = add(ans, A[1 << i]);
	printf("%d\n", ans);
}