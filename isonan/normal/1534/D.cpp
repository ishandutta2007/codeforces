#include <cstdio>
#include <algorithm>
#include <vector>

int n;
std::vector<int>query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	std::vector<int>ans;
	for(int i=1;i<=n;++i){
		int tem;
		scanf("%d",&tem);
		ans.push_back(tem);
	}
	return ans;
}
int d[2001],num[2001],fa[2001];
bool cmp(int a,int b){
	return d[a]<d[b];
}
int main(){
	scanf("%d",&n);
	if(n==2){
		puts("!\n1 2");
		fflush(stdout);
		return 0;
	}
	std::vector<int>dep=query(1);
	int cnt=0;
	for(int i=1;i<=n;++i)d[i]=dep[i-1];
	for(int i=1;i<=n;++i)if(d[i]&1)++cnt;
	for(int i=1;i<=n;++i)num[i]=i;
	std::sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;++i)if(d[i]==1)fa[i]=1;
	if((cnt<<1)>=n){
		for(int i=2;i<=n;++i){
			if(d[num[i]]%2==0){
				std::vector<int>tem=query(num[i]);
				int u=num[i];
				int x=0,y=0;
				for(int i=1;i<=n;++i){
					if(tem[i-1]==1&&d[i]==d[u]-1)y=i;
					if(tem[i-1]==2&&d[i]==d[u]-2)x=i;
					if(tem[i-1]==1&&d[i]==d[u]+1)fa[i]=u;
				}
				fa[u]=y;
				if(x)fa[y]=x;
			}
		}
	}
	else{
		for(int i=2;i<=n;++i){
			if(d[num[i]]%2==1){
				std::vector<int>tem=query(num[i]);
				int u=num[i];
				int x=0,y=0;
				for(int i=1;i<=n;++i){
					if(tem[i-1]==1&&d[i]==d[u]-1)y=i;
					if(tem[i-1]==2&&d[i]==d[u]-2)x=i;
					if(tem[i-1]==1&&d[i]==d[u]+1)fa[i]=u;
				}
				fa[u]=y;
				if(x)fa[y]=x;
			}
		}
	}
	puts("!");
	for(int i=2;i<=n;++i)printf("%d %d\n",i,fa[i]);
	fflush(stdout);
}