#include <cstdio>
#include <algorithm>

int n,m,stk[500001],top;
int Base[500001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int f[500010];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d%d",&n,&m);
	int ans=0,mul=1;
	for(int i=1;i<=500000;i++)Base[i]=-1;
	for(int i=1,k;i<=n;i++){
		k=read();
		int p1=0,p2=0;
		p2=read();
		if(k>1)p1=read();
		if(find(p1+1)==find(p2+1))continue;
		f[find(p1+1)]=find(p2+1);
		stk[++top]=i;
			mul=1ll*mul*2%1000000007;
	}
	printf("%d %d\n",mul,top);
	for(int i=1;i<=top;i++)write(stk[i]),putchar(' ');
}