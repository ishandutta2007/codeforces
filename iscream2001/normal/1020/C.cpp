#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N=100005;
const LL inf=1e18;
int n,m,tot;
int cnt[3010];
LL p[3010];
LL sum[3010][3010];
int main(){
	int u,t;LL w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%I64d",&u,&w);
		++cnt[u];sum[u][cnt[u]]=w;
	}
	for(int i=1;i<=m;++i)
		if(cnt[i]>0)
			sort(sum[i]+1,sum[i]+cnt[i]+1);
	LL ans=inf,re;
	int j;
	for(int k=0;k<=n-cnt[1];++k){
		u=k+cnt[1];t=0;re=0;tot=0;
	//	cout<<u<<endl;
		for(int i=2;i<=m;++i){
			j=1;
			if(cnt[i]>=u){
				for(;j<=cnt[i]-u+1;++j){
					++t;re+=sum[i][j];
				}
			}
			for(;j<=cnt[i];++j)
				p[++tot]=sum[i][j];
		}
		sort(p+1,p+1+tot);
		j=1;
		while(t<k){
			++t;
			re+=p[j];
			++j;
		}
	//	cout<<re<<endl;
		ans=min(ans,re);
	}
	printf("%I64d\n",ans);
	return 0;
}