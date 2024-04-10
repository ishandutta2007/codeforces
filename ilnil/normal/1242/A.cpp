#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5,mo=1e9+7;
ll n,ans;
int ps,p[N];
bool bz[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,2,N-5){
		if(!bz[i])p[++ps]=i;
		for(int j=1,u;(u=i*p[j])<=N-5;++j){
			bz[u]=1;
			if(i%p[j]==0)break;
		}
	}
	if(n==1){
		printf("%d\n",1);
		return 0;
	}
	int cnt=0;
	ll ans;
	fo(i,1,ps)if(n%p[i]==0){
		for(;n%p[i]==0;)n/=p[i];
		ans=p[i];
		++cnt;
	}
	if(n>1){
		++cnt;
		ans=n;
	}
	if(cnt>1)printf("%d\n",1);
	else printf("%lld\n",ans);
}