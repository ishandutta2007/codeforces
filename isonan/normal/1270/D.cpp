#include <cstdio>
#include <vector>
#include <algorithm> 

int n,k,a[100001],mn,ans,p1,p2;
bool vis[100001],in[100001];
std::vector<int>vec;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)vis[i]=1;
	for(int i=1;i<=n-k+1;i++){
		printf("? ");
		for(int j=1;j<=n;j++)if(vis[j])printf("%d ",j);
		putchar('\n');
		fflush(stdout);
		int p;
		scanf("%d",&p);
		scanf("%d",a+p);
		vis[p]=0;
		in[p]=1;
		if(i+k<=n)vis[i+k]=1;
		if(!p1)p1=p;
		else p2=p;
	}
	if(a[p1]>a[p2])std::swap(p1,p2);
	for(int i=1;i<=n;i++)if(!in[i])vec.push_back(i);
	for(int i=0;i<vec.size();i++){
		printf("? ");
		for(int j=0;j<vec.size();j++)
			if(i!=j)printf("%d ",vec[j]);
		printf("%d %d\n",p1,p2);
		fflush(stdout);
		int p;
		scanf("%d",&p);
		scanf("%d",a+p);
		if(p==p2)++ans;
	}
	printf("! %d\n",ans+1);
	fflush(stdout);
}