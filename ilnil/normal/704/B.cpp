#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
#define inf 1e18
#define cmin(a,b)a=min(a,b)
using namespace std;
const int N=5005;
int n,s,e,x[N],a[N],b[N],c[N],d[N],o,now;
ll f[2][N];
inline int pd(int x){return x?(x==1?1:2):0;}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>s>>e;
	fo(i,1,n)cin>>x[i];
	fo(i,1,n)cin>>a[i],a[i]+=x[i];
	fo(i,1,n)cin>>b[i],b[i]-=x[i];
	fo(i,1,n)cin>>c[i],c[i]+=x[i];
	fo(i,1,n)cin>>d[i],d[i]-=x[i];
	fo(i,0,n)f[0][i]=inf;
	f[0][0]=0;
	fo(go,1,n){
		o^=1;
		fo(i,0,n)f[o][i]=inf;
		ll v;
		int ad=now?(now==1?1:-1):0;
		fo(i,0,n)if((v=f[!o][i])<inf){
			int j=i+ad;
			if(go!=s&&go!=e){
				if(i+j-2>0||go==n)cmin(f[o][i-1],v+a[go]+c[go]);
				if(i)cmin(f[o][i],v+b[go]+c[go]);
				if(j)cmin(f[o][i],v+a[go]+d[go]);
				cmin(f[o][i+1],v+b[go]+d[go]);
			}else{
				if(go==s){
					if(i-1+j>0||go==n&&i)cmin(f[o][i-1],v+c[go]);
					cmin(f[o][i],v+d[go]);
				}else{
					if(i+j-1>0||go==n&&j)cmin(f[o][i],v+a[go]);
					cmin(f[o][i+1],v+b[go]);
				}
			}	
		}
		if(go==s)now=pd(ad+1);
		if(go==e)now=pd(ad-1);
	}
	cout<<f[o][0];
}