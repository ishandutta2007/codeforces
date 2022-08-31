#include <cstdio>

int n;
int a[100001],b[100001],pos[100001],cnt;
bool vis[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i),pos[b[i]]=i;
	int now=1;
	for(int i=1;i<=n;i++){
		if(vis[a[i]])continue;
		while(now<pos[a[i]]){
			++cnt;
			vis[b[now]]=1;
			++now;
		}
		++now;
	}
	printf("%d\n",cnt);
}