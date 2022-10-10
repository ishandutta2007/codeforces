#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=1600010,mod=998244353,p=3,p2=332748118;
int i,j,k,n,m,R[maxn];
ll a[maxn],A[maxn],B[maxn],C[maxn],tmp[maxn],S[maxn][2],I[maxn],LL[maxn];
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
inline ll get(bool op,int c){
	if(S[c][op])return S[c][op];
	return S[c][op]=ksm(op? p:p2,(mod-1)/(c*2));
}
void NTT(int len,ll *a,int op){
	for(int i=0;i<len;i++)tmp[R[i]]=a[i];
	for(int i=0;i<len;i++)a[i]=tmp[i];
	ll Wn,w;
	for(int i=1;i<len;i*=2){
		Wn=get(op,i);
		for(int j=0;j<len;j+=i*2){
			w=1;
			for(int k=0;k<i;k++,w=w*Wn%mod){
				int K=k+j;
				ll S1=a[K],S2=a[K+i]*w%mod;
				a[K]=(S1+S2)%mod;
				a[K+i]=(S1-S2+mod)%mod;
			}
		}
	}
}
ll tmp2[2][maxn];
void mul(int len,int L,ll *A,ll *B,ll *C){
	for(int i=0;i<len;i++)tmp2[0][i]=A[i];
	for(int i=0;i<len;i++)tmp2[1][i]=B[i];
	for(int i=0;i<len;i++)R[i]=R[i/2]/2+((i&1)*(1<<L-1));
	NTT(len,tmp2[0],1);NTT(len,tmp2[1],1);
	for(int i=0;i<len;i++)C[i]=tmp2[0][i]*tmp2[1][i]%mod;
	NTT(len,C,0);
	for(int i=0;i<len;i++)C[i]=C[i]*LL[L]/*ksm(len,mod-2)*/%mod;
}
void getn(int n,ll *a){
	int Len=1,len=2;
	for(int i=0;i<n*4;i++)A[i]=B[i]=C[i]=0;
	A[0]=ksm(a[0],mod-2);
	for(;len<=n*2;len*=2,Len++){
		for(int j=0;j<len;j++)B[j]=a[j];
		mul(len*2,Len+1,A,B,C);C[0]=2-C[0];
		for(int j=1;j<len*2;j++)C[j]=-C[j];
		for(int j=0;j<len*2;j++)B[j]=C[j];
		mul(len*2,Len+1,A,B,C);
		for(int j=0;j<len;j++)A[j]=C[j];
		for(int j=len;j<len*2;j++)A[j]=0;
	}for(int i=0;i<len;i++)a[i]=A[i];
}
ll TMP[maxn];
void getln(int n,ll *a){
	int len=2,Len=1;
	while(len<=n*2)len*=2,Len++;
	for(int i=0;i<n;i++)TMP[i]=a[i];
	getn(n,a);
	for(int i=0;i<n;i++)B[i]=(i+1)*TMP[i+1]%mod;
	mul(len*2,Len+1,a,B,C);
	for(int i=n;i<len;i++)a[i]=0;
	for(int i=1;i<n;i++)a[i]=C[i-1]*I[i]%mod;
	a[0]=0;
}
ll Ans[maxn],A2[maxn],A3[maxn],A4[maxn];
void getexp(int n,ll *a){
	Ans[0]=1;int len=2,Len=1;
	for(;len<=n*2;len<<=1,Len++){
		for(int i=0;i<len;i++)A2[i]=A3[i]=Ans[i];getln(len,A3);
		for(int i=0;i<len;i++)A3[i]=(-A3[i]+a[i]+mod)%mod;A3[0]=(A3[0]+1)%mod;
		mul(len*2,Len+1,A2,A3,A4);
		for(int i=0;i<len;i++)Ans[i]=A4[i];
	}for(int i=0;i<n;i++)a[i]=Ans[i];
}ll last=1;
ll F[maxn],H[maxn],G[maxn];
void getsqrt(int n,ll *a){
	int len=2,Len=1;
	G[0]=1;
	for(;len<=2*n;len<<=1,Len++){
		for(int i=0;i<len/2;i++)H[i]=G[i];mul(len,Len,H,G,F);
		for(int i=0;i<len/2;i++)H[i]=2*H[i]%mod;getn(len/2,H);
		for(int i=0;i<len;i++)F[i]=(F[i]+a[i])%mod;mul(len*2,Len+1,H,F,G);
		for(int i=len;i<2*len;i++)G[i]=0;
	}for(int i=0;i<n;i++)a[i]=G[i];
}
int c[maxn];
int main() {
	cin>>n>>m;
	for(i=1;i<maxn/16;i++)I[i]=ksm(i,mod-2);
	for(i=0;i<110;i++)LL[i]=ksm(last,mod-2),last=last*2%mod;
	for(i=0;i<n;i++)a[read()]=1;
	for(i=0;i<maxn;i++)a[i]=(-4*a[i])%mod;
	a[0]++;getsqrt(100001,a);
	a[0]++;getn(100001,a);
	for(i=1;i<=m;i++)printf("%lld\n",2*a[i]%mod);puts("");
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}