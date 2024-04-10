#include <cstdio>
#include <algorithm>

int n,d,f[1001],g[1001],now=1,num[1001],top;
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)g[i]=1;
	for(int i=1,x,y,sp=0;i<=d;++i){
		scanf("%d%d",&x,&y);
		x=find(x),y=find(y);
		// printf("%d %d\n",find(x),find(y));
		if(find(x)!=find(y)){
			g[y]+=g[x];
			f[x]=y;
		}
		else ++sp;
		top=0;
		for(int j=1;j<=n;++j)
			if(!f[j])num[++top]=g[j];
		std::sort(num+1,num+top+1);
		// for(int j=1;j<=n;++j)printf("%d ",f[j]);putchar('\n');
		// for(int j=1;j<=top;++j)printf("%d ",num[j]);putchar('\n');
		// printf("%d\n",sp);
		int ans=0;
		for(int j=top;j&&(top-j)<=sp;--j){
			ans+=num[j];
		}
		printf("%d\n",ans-1);
	}
}