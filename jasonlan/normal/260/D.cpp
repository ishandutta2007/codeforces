#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=101000;
int n;
int num[2][maxn],val[2][maxn],cnt[2];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1,c;i<=n;++i){
		c=read();
		num[c][++cnt[c]]=i;
		val[c][cnt[c]]=read();
	}
	for(register int i=1,g;i<=n-1;++i){
		g=min(val[0][cnt[0]],val[1][cnt[1]]);
		printf("%d %d %d\n",num[0][cnt[0]],num[1][cnt[1]],g);
		val[0][cnt[0]]-=g;val[1][cnt[1]]-=g;
		if(cnt[0]>1&&!val[0][cnt[0]])--cnt[0];
		else if(cnt[1]>1&&!val[1][cnt[1]])--cnt[1];
	}
	return 0;
}