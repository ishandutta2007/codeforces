#include<bits/stdc++.h>
using namespace std;
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int n,x,y,num1[210000],num2[210000],col[210000];
int edgenum=1,vet[410000],Next[410000],Head[210000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
	for (int e=Head[u];e;e=Next[e])
		if (col[vet[e]]==-1){
			col[vet[e]]=col[u]^1;
			dfs(vet[e]);
		}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		x=read(); y=read();
		if (num1[x]) addedge(i,num1[x]),addedge(num1[x],i),num1[x]=0;
		else num1[x]=i;
		if (num2[y]) addedge(i,num2[y]),addedge(num2[y],i),num2[y]=0;
		else num2[y]=i;
		col[i]=-1;
	}
	for (int i=1;i<=n;i++)
		if (col[i]==-1) col[i]=0,dfs(i);
	for (int i=1;i<=n;i++)
		if (col[i]) putchar('r');
		else putchar('b');
	return 0;
}