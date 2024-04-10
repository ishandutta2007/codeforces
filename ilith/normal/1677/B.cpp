#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=1e6+7;
int T,n,m,k,su,vs[N],sum[N];
int ans[N];
char s[N];
void solve(){
	scanf("%d%d",&n,&m),k=n*m;
	scanf("%s",s+1),su=0;
	FOR(i,0,m)vs[i]=0;
	FOR(i,1,k){
		if(s[i]=='1'&&vs[i%m]==0)vs[i%m]=1,su++;
		ans[i]=su;
	}
	su=0;
	FOR(i,1,k){
		su+=s[i]=='1';
		if(i<=m){
			sum[i]=!!su;
		}
		else{
			su-=s[i-m]=='1';
			sum[i]=sum[i-m]+!!su;
		}
		ans[i]+=sum[i];
	}
	FOR(i,1,k)printf("%d ",ans[i]),ans[i]=0;
	puts("");
}
signed main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}