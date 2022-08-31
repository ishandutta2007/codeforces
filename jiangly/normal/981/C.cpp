#include<bits/stdc++.h>
const int MAXN=100000;
int N;
int Root;
int Deg[MAXN+5];
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++Deg[u];
		++Deg[v];
	}
	for(int i=1;i<=N;++i)
		if(Deg[i]>2)
			if(Root){
				puts("No");
				return 0;
			}else
				Root=i;
	puts("Yes");
	if(Root){
		printf("%d\n",Deg[Root]);
		for(int i=1;i<=N;++i)
			if(Deg[i]==1)
				printf("%d %d\n",Root,i);
	}else{
		puts("1");
		for(int i=1;i<=N;++i)
			if(Deg[i]==1)
				printf("%d ",i);
	}
	return 0;
}