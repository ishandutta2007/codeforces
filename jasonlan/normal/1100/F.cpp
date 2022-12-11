#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500010;
int n,q;
int pre[21][maxn];
int preb[21][maxn],val[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void getpre(int p){
	for(register int i=20;~i;--i){
		pre[i][p]=pre[i][p-1];
		preb[i][p]=preb[i][p-1];
	}
	int u=p,x=val[p];
	for(register int i=20;~i;--i)
		if((x>>i)&1){
			if(!preb[i][p]){
				preb[i][p]=x;pre[i][p]=u;
				break;
			}
			if(u>pre[i][p]){
				swap(preb[i][p],x);swap(pre[i][p],u);
			}
			x^=preb[i][p];
		}
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i){
		val[i]=read();
		getpre(i);
	}
	q=read();
	for(register int i=0,l,r;i<q;++i){
		l=read();r=read();
		int ans=0;
		for(register int i=20;~i;--i)
			if(l<=pre[i][r])
				ans=max(ans,ans^preb[i][r]);
		printf("%d\n",ans);
	}
	return 0;
}