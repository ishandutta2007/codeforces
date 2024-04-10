#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
const int mo=998244353,g=3,M=1<<18;
int qp(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
void dft(int *a,int n,int fl=1){
	for (int i=n>>1,j=1,k;j<n-1;j++){
		if(i>j)swap(a[i],a[j]);
		for (k=n>>1;k<=i;k>>=1)i^=k;i^=k;
	}
	for (int m=2;m<=n;m<<=1)
		for (int i=0,wm=qp(g,fl==1?(mo-1)/m:(mo-1)/m*(m-1));i<n;i+=m)
			for (int j=i,w=1;j<i+(m>>1);j++){
				int u=a[j],v=1ll*w*a[j+(m>>1)]%mo;
				if((a[j]=u+v)>=mo)a[j]-=mo;
				if((a[j+(m>>1)]=u-v)<0)a[j+(m>>1)]+=mo;
				w=1ll*w*wm%mo;
			}
	if(fl==-1){
		int tm=qp(n,mo-2);
		for (int i=0;i<n;i++)a[i]=1ll*a[i]*tm%mo;
	}
}
int tmp[M],rb[M],tmp1[M],a[M],b[M],c[M];
void inv(int *a,int n,int *b){
	b[0]=qp(a[0],mo-2);b[1]=0;
	for (int m=2;m<=n;m<<=1){
		for (int i=0;i<m;i++)tmp[i]=a[i];for (int i=m;i<2*m;i++)tmp[i]=b[i]=0;
		dft(tmp,2*m);dft(b,2*m);
		for (int i=0;i<2*m;i++)b[i]=1ll*b[i]*(2-1ll*tmp[i]*b[i]%mo+mo)%mo;
		dft(b,2*m,-1);for (int i=m;i<2*m;i++)b[i]=0;		
	}
}
void squarert(int *a,int n,int *b){
	b[0]=1;b[1]=0;
	int r2=qp(2,mo-2);
	for (int m=2;m<=n;m<<=1){
		for (int i=0;i<m;i++)tmp1[i]=a[i];for (int i=m;i<2*m;i++)tmp1[i]=b[i]=0;
		dft(tmp1,2*m);
		inv(b,m,rb);
		dft(rb,2*m);
		dft(b,2*m);		
		for (int i=0;i<2*m;i++)b[i]=(1ll*r2*b[i]+1ll*r2*tmp1[i]%mo*rb[i])%mo;		
		dft(b,2*m,-1);
		for (int i=m;i<2*m;i++)b[i]=0;
	}
}
void gn(int &x){char c;while((c=getchar())<'0'||c>'9');x=c-'0';while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';}
int main()
{
	int n,m,N=1;gn(n);gn(m);
	while(N<=m)N<<=1;
	while(n--){int x;gn(x);a[x]=mo-4;}a[0]=1;
	squarert(a,N,b);
	b[0]+=1;
	inv(b,N,c);
	for (int i=1;i<=m;i++)printf("%d\n",c[i]*2%mo);
	return 0;
}