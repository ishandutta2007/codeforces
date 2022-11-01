#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define ll long long
#define add(x,y)((x+y)-(x+y>=mo?mo:0))
using namespace std;
const int N=262200,mo=998244353;
int n,a,b,h[N],Q,P,nn,d[N];
ll w[N],A[N],B[N],X[N],nQ;
ll ksm(ll x,int y){
	ll t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
void dft(ll *a){
	fo(i,1,Q)if(i<h[i])swap(a[i],a[h[i]]);ll A;
	for(int i=2,j,m,k,g=1;m=i>>1,i<=Q;g++,i<<=1)for(j=0;j<Q;j+=i)for(k=0;k<m;k++){
		ll &l=a[j+k],&r=a[j+m+k];	
		A=w[(P>>g)*k]*r%mo;r=add(l,mo-A);l=add(l,A);
	}
}
void idft(ll *a){
	fo(i,1,Q>>1)swap(a[i],a[Q-i]);dft(a);
	fo(i,0,Q)a[i]=a[i]*nQ%mo;
}
ll s(int n,int a){
	if(n==-1&&a==0||n==0&&a==1)return 1;
	if(a<=0)return 0;
	for(P=1;P<=n*2;P<<=1);
	w[0]=1;w[1]=ksm(3,(mo-1)/P);
	fo(i,2,P)w[i]=w[i-1]*w[1]%mo;
	fo(i,1,n)d[i]=i*2-2,X[i*2-2]=i,X[i*2-1]=1;nn=n;d[nn+1]=n*2;
	for(Q=4,nQ=mo+1>>1;nn>1;Q<<=1,(nn&1?d[nn+1>>1]=d[nn]:0),d[(nn=(nn>>1)+(nn&1))+1]=n*2){
		fo(i,1,Q)h[i]=(i&1)*(Q>>1)|(h[i>>1]>>1);nQ=nQ*(mo+1>>1)%mo;
		fo(i,1,nn>>1){
			int x=i*2-1;
			fo(j,0,d[x+1]-d[x]-1)A[j]=X[j+d[x]];
			fo(j,0,d[x+2]-d[x+1]-1)B[j]=X[j+d[x+1]];
			dft(A);dft(B);
			fo(j,0,Q)A[j]=A[j]*B[j]%mo,B[j]=0;
			idft(A);d[i]=d[x];
			fo(j,0,d[x+2]-d[x]-1)X[j+d[x]]=A[j],A[j]=0;
		}
	}
	return X[a-1];
}
ll c(int a,int b){
	ll f[N];f[0]=1;
	fo(i,1,a)f[i]=f[i-1]*i%mo;
	return f[a]*ksm(f[b],mo-2)%mo*ksm(f[a-b],mo-2)%mo;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",s(n-2,a+b-2)*c(a+b-2,a-1)%mo);
}