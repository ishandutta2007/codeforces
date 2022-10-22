#include<bits/stdc++.h>
using namespace std;
int n;
int a[109];
bool vis[109];
void work(){
	scanf("%d",&n);
	int ans=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		bool bol=0;
		for(int j=1;j<i;++j){
			if(!vis[j]&&a[j]<a[i]){
				vis[j]=1;
				bol=1;
				break;
			}
		}
		if(!bol)ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}