#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e7+5,mo=1e9+7;
int n,a,ma,ans,ans2,mu[N],f[N];
int p[N],ps;
bool b[N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,1,n)cin>>a,++f[a],ma=max(ma,a);
	mu[1]=1;
	fo(i,2,ma){
		if(!b[i]){
			p[++ps]=i;mu[i]=-1;
			fd(j,1,ma/i)f[j]+=f[j*i];
		}
		for(int j=1,u;(u=i*p[j])<=ma;++j){
			b[u]=1;
			if(i%p[j]==0)break;
			mu[u]=-mu[i];
		}
	}
	fo(i,1,ma)if(mu[i]&&f[i]){
		a=ksm(2,f[i]);
		ans2=((a-1)*mu[i]+ans2)%mo;
		a=(ll)a*(mo+1>>1)%mo*f[i]%mo;
		ans=(a*mu[i]+ans)%mo;
	}
	cout<<((ll)ans*2-(ll)ans2*n%mo+(ll)mo*3)%mo;
}