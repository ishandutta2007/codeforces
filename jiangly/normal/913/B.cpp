#include<bits/stdc++.h>
const int MAXN=1000;
int n;
int fa[MAXN+5],degree[MAXN+5],cnt[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		++degree[fa[i]];
	}
	for(int i=1;i<=n;++i){
		if(!degree[i]){
			++cnt[fa[i]];
		}
	}
	for(int i=1;i<=n;++i){
		if(degree[i]&&cnt[i]<3){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}