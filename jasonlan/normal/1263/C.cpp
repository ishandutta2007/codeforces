#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=121000;
int n,cnt;
int ans[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		n=read();cnt=0;
		for(register int i=1,k;i<=n;i=k+1){
			k=n/(n/i);
			ans[++cnt]=n/i;
		}
		ans[++cnt]=0;
		printf("%d\n",cnt);
		for(register int i=1;i<=cnt;++i)
			printf("%d ",ans[cnt-i+1]);
		printf("\n");
	}
	return 0;
}