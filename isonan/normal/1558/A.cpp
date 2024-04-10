#include <cstdio>

int t;
bool vis[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		int a,b;
		scanf("%d%d",&a,&b);
		int t1=(a+b+1)>>1,t2=(a+b)>>1;
		for(int i=0;i<=a+b;++i)vis[i]=0;
		for(int i=0;i<=a&&i<=t1;++i){
			if(t2>=a-i){
				vis[t1-i+a-i]=1;
				vis[(a+b)-(t1-i+a-i)]=1;
			}
		}
		int cnt=0;
		for(int i=0;i<=a+b;++i)if(vis[i])++cnt;
		printf("%d\n",cnt);
		for(int i=0;i<=a+b;++i)if(vis[i])printf("%d ",i);putchar('\n');
	}
}