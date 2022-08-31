#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int t,match[101],a[51][51],n;
std::vector<std::pair<int,int> >vec[51];
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),vec[i].push_back(std::make_pair(a[i][j],j));
		for(int i=1;i<=n;i++)std::sort(vec[i].begin(),vec[i].end());
		puts("B");fflush(stdout);
		char ch=getchar();
		while(ch!='I'&&ch!='D')ch=getchar();
		int start;
		scanf("%d",&start);
		if((ch=='I')^(start<=n)){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					a[i][j]=n*n-a[i][j]+1;
		}else for(int i=1;i<=n;i++)std::reverse(vec[i].begin(),vec[i].end());
		//
		memset(match,0,sizeof match);
		for(int i=1;;i++){
			bool check=0;
			for(int j=1;j<=n;j++)
				if(!match[j]){
					check=1;
					int u=vec[j].back().second;
					vec[j].pop_back();
					match[j]=u+n;
					if(!match[u+n]||a[j][u]>a[match[u+n]][u])match[u+n]=j;
				}
			for(int j=1;j<=n;j++)
				if(match[match[j]]!=j)match[j]=0;
			if(!check)break;
		}
		for(;~start;){
			printf("%d\n",match[start]);
			fflush(stdout);
			scanf("%d",&start);
		}
	}
}