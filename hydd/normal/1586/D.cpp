#include<bits/stdc++.h>
using namespace std;
int n,nxt[110],Ans[110]; bool vis[110];
int querypre(int x){
	putchar('?');
	for (int i=1;i<=n;i++){
		putchar(' ');
		if (x==i) putchar('1');
		else putchar('2');
	}
	putchar('\n');
	fflush(stdout); scanf("%d",&x);
	return x;
}
int querysuf(int x){
	putchar('?');
	for (int i=1;i<=n;i++){
		putchar(' ');
		if (x==i) putchar('2');
		else putchar('1');
	}
	putchar('\n');
	fflush(stdout); scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n); int x;
	for (int i=1;i<=n;i++){
		x=querypre(i); if (x!=i) nxt[x]=i;
		x=querysuf(i); if (x!=i) nxt[i]=x;
	}
	for (int i=1;i<=n;i++) vis[nxt[i]]=true;
	int u=0;
	for (int i=1;i<=n;i++)
		if (!vis[i]) u=i;
	int cnt=0;
	while (u){ Ans[u]=++cnt; u=nxt[u];}
	putchar('!');
	for (int i=1;i<=n;i++) printf(" %d",Ans[i]); putchar('\n');
	return 0;
}