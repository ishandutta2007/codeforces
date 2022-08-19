#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>

int n,m,b,p[11],need[102][101],sum[101],match[101],back[101];
bool vis[10001];
bool judge(int u){
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(sum[i]>(u<<1))return 0;
		else if(sum[i]>u)cnt+=p[i];
	}
	return cnt<=b;
}
int ans[3][1000001],top;
void add(int kid,int time,int machine){
	if(machine>m)machine-=m;
	++top;
	ans[0][top]=kid;
	ans[1][top]=machine;
	ans[2][top]=time;
}
bool find(int x){
	for(int i=1;i<=(m<<1)+n;i++)
		if(need[x][i]&&!vis[i]){
			vis[i]=1;
			if(!back[i]||find(back[i])){
				back[i]=x;
				match[x]=i;
				return 1;
			}
		}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=m;i++)scanf("%d",p+i);
	for(int i=1,tem,x,t;i<=n;i++){
		scanf("%d",&tem);
		for(int j=1;j<=tem;j++){
			scanf("%d%d",&x,&t);
			need[i][x]=t;
			sum[x]+=t;
		}
	}
	int l=0,r=1000000,mid,ans;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++)
			sum+=need[i][j];
		l=std::max(l,sum);
	}
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
		printf("%d",sum[i]>ans),vis[i]=(sum[i]>ans);
	putchar('\n');
	for(int i=1;i<=m;i++){
		sum[i]=0;
		for(int j=1;j<=n;j++)
			if(sum[i]+need[j][i]>ans){
//				printf("%d %d %d\n",sum[i],need[j][i],ans);
				int u=need[j][i]-ans+sum[i];
				sum[i]+=ans-sum[i];
				need[j][i]-=u;
				need[j][i+m]+=u;
			}else sum[i]+=need[j][i];
//	for(int i=1;i<=n+(m<<1);i++)
//		for(int j=1;j<=n+(m<<1);j++)
//			assert(need[i][j]>=0);
	}
	int cnt=(m<<1)+1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m<<1;j++)sum+=need[i][j];
		sum=ans-sum;
		for(;sum;){
			if(::sum[cnt]+sum>ans){
				int u=ans-::sum[cnt];
				need[i][cnt]+=u;
				::sum[cnt]+=u;
				sum-=u;
				++cnt;
			}else{
				need[i][cnt]+=sum;
				::sum[cnt]+=sum;
				sum=0;
			}
		}
	}
	cnt=n+1;
	for(int i=1;i<=n+(m<<1);i++)::sum[i]=0;
	for(int i=1;i<=n+(m<<1);i++){
		int sum=0;
		for(int j=1;j<=n;j++)sum+=need[j][i];
		sum=ans-sum;
		for(;sum;){
			if(::sum[cnt]+sum>ans){
				int u=ans-::sum[cnt];
				::sum[cnt]+=u;
				need[cnt][i]+=u;
				sum-=u;
				++cnt;
			}else{
				need[cnt][i]+=sum;
				::sum[cnt]+=sum;
				sum=0;
			}
		}
	}
	for(int i=1;i<=n+(m<<1);i++){
		int cnt=0;
		for(int j=1;j<=n+(m<<1);j++)cnt+=need[i][j];
		assert(cnt==ans);
	}
	for(int i=1;i<=n+(m<<1);i++){
		int cnt=0;
		for(int j=1;j<=n+(m<<1);j++)cnt+=need[j][i];
		assert(cnt==ans);
	}
//	return 0;
	for(int i=0;i<ans;i++){
		bool cando=1;
		for(int j=1;j<=n+(m<<1);j++)cando&=(need[j][match[j]]!=0);
		if(!cando){
			for(int j=1;j<=n+(m<<1);j++)match[j]=0;
			for(int j=1;j<=(m<<1)+n;j++)back[j]=0;
			for(int j=1;j<=n+(m<<1);j++){
				memset(vis,0,sizeof vis);
				find(j);
			}
		}
//		for(int j=1;j<=n+(m<<1);j++)printf("%d ",match[j]);putchar('\n');
		for(int j=1;j<=n+(m<<1);j++)--need[j][match[j]];
		for(int j=1;j<=n;j++)if(match[j]<=(m<<1))add(j,i,match[j]);
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
		printf("%d %d %d 1\n",::ans[0][i],::ans[1][i],::ans[2][i]);
}