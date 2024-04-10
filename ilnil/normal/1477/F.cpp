#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2005,mo=998244353;
int n,k,tot,sum,ans,l;
int len[N],fac[N],ifac[N],f[55][N],g[2][N],h[55][N];
int pw(int x,int y=mo-2){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	n=2000;
	fac[0]=1;
	fo(i,1,n)fac[i]=(ll)fac[i-1]*i%mo;
	ifac[n]=pw(fac[n]);
	fd(i,0,n-1)ifac[i]=(ll)ifac[i+1]*(i+1)%mo;
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	fo(i,1,n)scanf("%d",&len[i]),tot+=len[i];
	int itot=pw(tot);
	fo(i,1,n){
		l=len[i];
		int lk=(l-1)/k;
		fo(p,0,i)fo(j,0,sum+lk)h[p][j]=0;
		fo(j,0,lk)g[0][j]=(ll)ifac[j]*pw((ll)(l-j*k)*itot%mo,j)%mo*(j&1?-1:1);
		fo(j,1,lk)g[1][j]=(ll)ifac[j-1]*pw((ll)(l-j*k)*itot%mo,j-1)%mo*(j&1?-1:1);
		fo(p,0,i-1)fo(j,0,sum){
			int v=f[p][j];
			if(!v)continue;
			fo(q,0,1)fo(k,0,lk)
				h[p+q][j+k]=((ll)v*g[q][k]+h[p+q][j+k])%mo;
		}
		fo(p,0,i)fo(j,0,sum+lk)f[p][j]=h[p][j];
		sum+=lk;
	}
	f[0][0]=0;
	fo(p,0,n)fo(i,0,sum)
		if(f[p][i])
			ans=((ll)f[p][i]*pw((ll)itot*i*k%mo,mo-1-(i-p+1))%mo*fac[i-p]+ans)%mo;
	cout<<((ll)-ans+mo)%mo;
}