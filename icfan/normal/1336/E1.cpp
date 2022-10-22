#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=200000;
const int Maxm=45;
const int Mod=998244353;
int n,m;
ll a[Maxn+5];
ll t[Maxm+5],g[Maxm+5],cnt;
int ans[Maxm+5];
int f[Maxm+5][(1<<12)|5];
void work_dfs(int x,ll val){
	if(x>=m){
		ans[__builtin_popcountll(val)]++;
		return;
	}
	if(t[x]==0){
		work_dfs(x+1,val);
	}
	else{
		work_dfs(x+1,val);
		work_dfs(x+1,val^t[x]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll x=a[i];
		for(int j=m-1;j>=0;j--){
			if((x>>j)&1){
				if(t[j]==0){
					cnt++;
					t[j]=x;
					break;
				}
				x^=t[j];
			}
		}
	}
	for(int i=m-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if((t[i]>>j)&1){
				t[i]^=t[j];
			}
		}
	}
	for(int i=0;i<m;i++){
		if(t[i]>0){
			for(int j=0;j<m;j++){
				if(t[j]==0){
					g[i]=(g[i]<<1)|((t[i]>>j)&1);
				}
			}
		}
	}
	if(cnt<=25){
		work_dfs(0,0);
	}
	else{
		f[0][0]=1;
		for(int i=0,l=0;i<m;i++){
			if(t[i]==0){
				continue;
			}
			for(int j=l;j>=0;j--){
				for(int k=0;k<(1<<(m-cnt));k++){
					f[j+1][k^g[i]]=(f[j+1][k^g[i]]+f[j][k])%Mod;
				}
			}
			l++;
		}
		for(int v=0;v<(1<<(m-cnt));v++){
			int num=__builtin_popcountll(v);
			for(int i=0;i<=cnt;i++){
				ans[i+num]=(ans[i+num]+f[i][v])%Mod;
			}
		}
	}
	int res=quick_power(2,n-cnt,Mod);
	for(int i=0;i<=m;i++){
		ans[i]=1ll*ans[i]*res%Mod;
	}
	for(int i=0;i<=m;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}