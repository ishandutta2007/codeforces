#include <cstdio>

int n,t;
char str[300001];
int val[300001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)val[i]=(str[i]=='-')?-1:(str[i]=='>'?1:0);
		bool good=0;
		for(int i=0;i<2;i++){
			bool same=1;
			for(int j=1;j<=n;j++)same&=(val[j]==-1||val[j]==i);
			good|=same;
		}
		if(good){
			printf("%d\n",n);
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=(val[i]==-1||(val[i%n+1]==-1));
		}
		printf("%d\n",cnt);
	}
}