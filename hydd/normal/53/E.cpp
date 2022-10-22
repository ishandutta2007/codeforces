#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int n,m,k,u,v,upperlim;
int dp[1100][1100],tot[1100];
vector<int> vec[25];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v); u--; v--;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	upperlim=(1<<n)-1; tot[0]=0;
	for (int i=1;i<=upperlim;i++) tot[i]=tot[i>>1]+(i&1);
	for (int i=1;i<=upperlim;i<<=1) dp[i][i]=1;
	for (int i=1;i<=upperlim;i++)
		for (int j=i;j;j=(j-1)&i)
			if (dp[i][j]) 
				for (int u=0;u<n;u++)
					if (i&(1<<u)){
						int sz=vec[u].size();
						for (int k=0;k<sz;k++){
							v=vec[u][k];
							if (!(i&(1<<v))){
								int now;
								if (tot[i]==1) now=i|(1<<v);
								else now=((j|(1<<u))^(1<<u))|(1<<v);
								if (!(now>>(v+1))) dp[i|(1<<v)][now]+=dp[i][j];
							}
						}
					}
    ll ans=0;
    for (int i=0;i<=upperlim;i++) 
        if (tot[i]==k) ans+=dp[upperlim][i];
    printf("%lld\n",ans);
	return 0;
}