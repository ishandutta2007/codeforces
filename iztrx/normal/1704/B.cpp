#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 1000005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
int T,n,m,i,j,mn,mx,k,fl,x,y,ans,a[N];
char qwq,qaq;
string s,t;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i];
		ans=0;
		for(i=1;i<=n;i=j){
			j=i;mn=mx=a[i];
			while(j<=n&&mx-mn<=m*2){
				++j;
				mn=min(mn,a[j]);
				mx=max(mx,a[j]);
			}
			++ans;
		}
		cout<<ans-1<<"\n";
	}
}