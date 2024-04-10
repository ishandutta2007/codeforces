#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=3005,mo=998244353;
int n,c,a[N],ans[N],b[N],_[N],ny[N];
int f[N][1<<11],g[N][305];
void work1(){
	int mx=0,all=(1<<c)-1;
	f[0][0]=1;
	#define add(x,y)(x=((ll)x*2+y)%mo)
	fo(i,1,n){
		int A=a[i]-1;
		fo(j,0,mx)
			fo(k,0,(1<<c-A-1)-1)
				fo(l,0,(1<<A)-1)
					add(f[j][(k<<A+1)+(1<<A)+l],f[j][(k<<A+1)+l]);
		fo(j,0,mx)if(f[j][all]){
			f[j+1][0]=(f[j+1][0]+f[j][all])%mo;
			f[j][all]=0;
			if(mx==j)++mx;
		}
	}
	fo(i,0,n/c){
		ll su=0;
		fo(j,0,all)su+=f[i][j];
		ans[i]=su%mo;
	}
}
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
void work2(){
	_[0]=1;
	fo(i,1,n)_[i]=_[i-1]*2%mo;
	fo(i,0,n)ny[i]=ksm(_[i]-1,mo-2);ny[0]=1;
	g[0][0]=1;
	fo(i,0,n){
		int mx=i/c,all=0;
		ll su=_[n-i],xs,o=1;
		fo(j,1,c)b[j]=0;
		fo(j,i+1,n){
			!b[a[j]]++?++all:0;
			xs=o*ny[b[a[j]]-1]%mo;
			o=xs*(_[b[a[j]]]-1)%mo;
			if(all==c){
				su=(su-xs*_[n-j]%mo+mo)%mo;
				fo(k,0,mx)
					g[j][k+1]=((ll)g[i][k]*xs+g[j][k+1])%mo;
			}
		}
		fo(j,0,mx)ans[j]=((ll)g[i][j]*su+ans[j])%mo;
	}
}
int main(){
	scanf("%d%d",&n,&c);
	fo(i,1,n)scanf("%d",&a[i]);
	if(c<=11)work1();else work2();
	ans[0]=(ans[0]+mo-1)%mo;
	fo(i,0,n)printf("%d ",ans[i]);
}