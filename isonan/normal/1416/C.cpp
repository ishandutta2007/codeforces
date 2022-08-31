#include <cstdio>
#include <vector>
#include <map>

int n,cnt,x,a[300001],ch[2][10000001],size[10000001];
long long val[2][31];
void add(int x){
	int now=0;
	for(int i=30;~i;--i){
		int u=(x&(1<<i))!=0;
		val[u][i]+=size[ch[u^1][now]];
		if(!ch[u][now])ch[u][now]=++cnt;
		++size[now=ch[u][now]];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),add(a[i]);
	long long cnt=0;
	for(int i=30;~i;--i){
		cnt+=val[0][i]<val[1][i]?val[0][i]:val[1][i];
		if(val[0][i]>val[1][i])x|=1<<i;
	}
	printf("%lld %d",cnt,x);
}