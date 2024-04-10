#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,d;
int a[100009];
bool vis[100009];
void work(){
	int num=0;
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&d);
	vis[d]=1;
	for(int i=1;i<=10000;++i){
		int x=i;
		while(x){
			if(x%10==d)vis[i]=1;
			x/=10;
		}
		for(int j=1;j<=num;++j){
			if(i>=a[j])vis[i]|=vis[i-a[j]];
			if(vis[i]==1)break;
		}
		if(vis[i])a[++num]=i;
	}
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		if(x>10000||vis[x])printf("YES\n");
		else printf("NO\n"); 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}