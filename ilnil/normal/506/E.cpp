#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define add(x,y)(x=(x+y)%mo)
using namespace std;
const int N=310,mo=10007;
char c[N];
int n,m,ans,t;
int f[N][N][N],su[N];
struct mat{int a[N][N];}a,b;
long long c2[N][N];
mat operator*(const mat&a,const mat&b){
	mat c;memset(c2,0,sizeof c2);
	fo(i,1,t)fo(j,1,t)fo(k,1,t)c2[i][k]+=a.a[i][j]*b.a[j][k];
	fo(i,1,t)fo(j,1,t)c.a[i][j]=c2[i][j]%mo;
	return c;
}
mat ksm(mat x,int y){
	mat b;memset(b.a,0,sizeof b.a);
	fo(i,1,t)b.a[i][i]=1;
	for(;y;y>>=1,x=x*x)if(y&1)b=b*x;
	return b;
}
int main(){
	scanf("%s\n%d",c+1,&m);n=strlen(c+1);
	f[1][n][0]=1;
	fo(i,1,n)fd(j,i,n)
		if(c[i]==c[j]){
			fo(k,0,n)
				if(i+1<=j-1)add(f[i+1][j-1][k],f[i][j][k]);
				else add(su[k],f[i][j][k]);
		}else{
			fo(k,0,n-1){
				add(f[i+1][j][k+1],f[i][j][k]);
				add(f[i][j-1][k+1],f[i][j][k]);
			}
		}
	t=n+(n+1>>1)+1;
	a.a[t][t]=26;
	fo(i,1,n){
		a.a[i][i]=24;a.a[i][n+(n-i+1)/2]=su[i];
		if(i<n)a.a[i][i+1]=1;
	}
	fo(i,n+1,t-1){
		a.a[i][i]=25;
		if(i>n+1)a.a[i][i-1]=1;else a.a[i][t]=1;
	}
	b=ksm(a,n+m+1>>1);
	ans=(b.a[1][t]+su[0]*b.a[t-1][t])%mo;
	if(n+m&1){
		fo(i,0,n)su[i]=0;
		fo(i,1,n-1)if(c[i]==c[i+1])
			fo(j,0,n)add(su[j],f[i][i+1][j]);
		fo(i,1,n)a.a[i][n+(n-i+1)/2]=su[i];a.a[t][t]=0;
		b=ksm(a,n+m+1>>1);
		ans=((ans-b.a[1][t]-su[0]*b.a[t-1][t])%mo+mo)%mo;
	}
	cout<<ans;
}