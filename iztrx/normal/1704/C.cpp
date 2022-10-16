#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 1000005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
int T,n,m,i,j,mn,mx,l[N],k,fl,x,y,ans,a[N];
inline bool cmp(int x,int y){return x>y;}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;ans=0;
		for(i=1;i<=m;++i)cin>>a[i];
		sort(a+1,a+m+1);
		for(i=1;i<m;++i)l[i]=a[i+1]-a[i]-1;
		l[m]=a[1]+n-a[m]-1;
		sort(l+1,l+m+1,cmp);
		for(i=1;i<=m;++i){
			if(l[i]==4*i-3)++ans;
			else ans+=max(0,l[i]-4*i+3);
		}
		cout<<n-ans<<"\n";
	}
}