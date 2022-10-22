#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e6+10;
const int inf=1e8;
const LL P=998244353;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
LL n,m;
LL jc[N*3],inv[N*3];
LL f[N],A[N],B[N];
LL T[N],G[N],H[N];
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int main(){
	jc[0]=jc[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N*2;++i){
		jc[i]=jc[i-1]*i%P;
		inv[i]=(P-P/i)*inv[P%i]%P;
	}
	for(LL i=2;i<=N*2;++i){
		inv[i]=inv[i-1]*inv[i]%P;
	}
	cin>>n>>m;
	T[0]=jc[m-1];G[0]=jc[m-1];
	for(LL i=0;i<n;++i){
		G[i+1]=G[i];add(G[i+1],jc[m+i]*inv[i+1]%P);
		T[i+1]=T[i];add(T[i+1],G[i+1]);
	}
	for(LL i=1;i<=n;++i){
		A[i]=m*jc[i]%P*(n+m+1)%P*inv[m+i+1]%P*T[i]%P;
		B[i]=m*jc[i]%P*inv[m+i]%P*H[i-1]%P;
		f[i]=(A[i]+B[i])%P*qpow((P+1-m*inv[m+i]%P*jc[m-1+i]%P)%P,P-2)%P;
		H[i]=H[i-1];add(H[i],f[i]*inv[i]%P*jc[m+i-1]%P);
	}
	cout<<f[n]<<endl;
	return 0;
}