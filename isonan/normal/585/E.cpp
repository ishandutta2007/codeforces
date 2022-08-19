#include <cstdio>
#include <vector>

const int P=1000000007;
int top,n,Tem[11],g[10000001],stat[500001],pow;
long long fin;
void dfs1(int x,int i,int val,int v){
	if(x>top){
		if(!g[val])fin-=v;
		stat[g[val]]-=v;
		++g[val];
		stat[g[val]]+=v;
		return;
	}
	dfs1(x+1,i,val,v);
	dfs1(x+1,i,val*Tem[x],-v);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	n=read();
	for(int i=1,tem;i<=n;++i){
		tem=read();
		top=0;
		for(int j=2;j*j<=tem;++j)
			if(tem%j==0){
				Tem[++top]=j;
				while(tem%j==0)tem/=j;
			}
		if(tem>1)Tem[++top]=tem;
		dfs1(1,i,1,-1);
	}
	pow=1;
	fin=1ll*(fin+P)*n%P;
	for(int i=1;i<=n;i++)pow=2ll*pow%P,fin+=1ll*pow*(n-i)%P*(stat[i]+P)%P;
	printf("%d\n",fin%P);
}