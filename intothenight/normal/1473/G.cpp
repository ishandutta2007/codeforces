#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

const int MOD=998244353, PR=3;
vector<int> X, Y;
int F[300001], Finv[300001];

int mul(int a, int b) {return 1LL*a*b%MOD;}

int fast_pow(int a, int b)
{
    int ret=1;
    for(;b;b>>=1) {
        if(b&1) ret=mul(ret,a);
        a=mul(a,a);
    }
    return ret;
}

void FFT(vector<int> &A,bool inv)
{
	int N=A.size();
    vector<int> S;
	for(int i=0;i<N;i++) {
		int j=0;
		for(int b=1;b<N;b<<=1) {
			j<<=1;
			if(b&i) j|=1;
		}
		if(i<j) swap(A[i],A[j]);
	}
    S.push_back(fast_pow(inv ? fast_pow(PR,MOD-2):PR,MOD/N));
    for(int i=2;i<N;i<<=1) S.push_back(mul(S.back(),S.back()));
	for(int i=1;i<N;i<<=1) {
        int w=S.back();
        S.pop_back();
		for(int j=0;j<N;j+=i<<1) {
			int th=1;
			for(int k=0;k<i;k++) {
				int temp=mul(A[i+j+k],th);
				A[i+j+k]=A[j+k]-temp;
                if(A[i+j+k]<0) A[i+j+k]+=MOD;
				A[j+k]+=temp;
                if(A[j+k]>=MOD) A[j+k]-=MOD;
                th=mul(th,w);
			}
		}
	}
	if(inv) {
        int v=fast_pow(N,MOD-2);
        for(int i=0;i<N;i++) A[i]=mul(A[i],v);
    }
}

void conv(vector<int> &A, vector<int> &B)
{
	int N=1;
	for(;N<A.size()+B.size();N<<=1);
	A.resize(N); B.resize(N);
	FFT(A,false); FFT(B,false);
	for(int i=0;i<N;i++) A[i]=mul(A[i],B[i]);
	FFT(A,true);
}

int nCr(int n, int r)
{
	return mul(F[n],mul(Finv[r],Finv[n-r]));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N=1, M, ans=0;
	F[0]=Finv[0]=1;
	for(int i=1;i<=300000;i++) F[i]=mul(i,F[i-1]);
	Finv[300000]=fast_pow(F[300000],MOD-2);
	for(int i=300000;--i;) Finv[i]=mul(Finv[i+1],i+1);
	X.resize(1,1);
	for(cin>>M;M--;) {
		int a, b, sz=X.size()+10;
		cin>>a>>b;
		Y.clear();
		for(int i=-sz;i<=sz;i++) {
			if(b+i<0 || i>a) Y.push_back(0);
			else Y.push_back(nCr(a+b,b+i));
		}
		conv(X,Y);
		N+=a-b;
		for(int i=0;i<N;i++) X[i]=X[sz+i];
		X.resize(N);
	}
	for(int i=0;i<N;i++) {
		ans+=X[i];
		if(ans>=MOD) ans-=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}