#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=510000;
int n,c,ans;
int head[maxn],nxt[maxn],cnt[maxn];
bool vis[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();c=read();
	for(register int i=1,x;i<=n;++i){
		x=read();
		nxt[i]=head[x];head[x]=i;
		if(x==c){
			++cnt[i];vis[i]=true;
		}
		cnt[i]+=cnt[i-1];
	}
	ans=cnt[n];
	for(register int i=n;i;--i){
		if(vis[i])continue;
		for(register int j=i,dval=1;j;j=nxt[j]){
			vis[j]=true;
			ans=max(ans,dval+cnt[n]);
			dval=max(1,dval+1-(cnt[j]-cnt[nxt[j]]));
		}
	}
	printf("%d\n",ans);
	return 0;
}