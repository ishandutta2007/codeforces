#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 1000005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
struct node{
	ll x,y;
}a[N];
ll val[N];
int T,n,m,i,j,mn,mx,l[N],k,fl,x,y,ans;
inline bool cmp(node x,node y){return x.x<y.x;}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i){
			val[i]=0;
			for(j=1;j<=m;++j){
				cin>>x,val[i]+=1ll*j*x;
			}
			a[i].x=val[i];
			a[i].y=i;
		}
		sort(a+1,a+n+1,cmp);
		cout<<a[n].y<<" "<<a[n].x-a[n-1].x<<"\n";
	}
}