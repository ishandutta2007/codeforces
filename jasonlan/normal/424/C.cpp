#include<iostream>
#include<cstdio>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=1001000;
int n,ans;
bool isadd[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
void calc(){
	for(register int i=1,cnt,rlim;i<=n;++i){
		cnt=n/i+1;//0ni 
		rlim=n%i;
		if(cnt&1)isadd[0]^=1;
		else isadd[i]^=1;
		isadd[rlim+1]^=1;
	}
	for(register int i=1;i<n;++i){
		isadd[i]^=isadd[i-1];
		if(isadd[i])ans^=i;
	}
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		ans^=read();
	calc();
	printf("%d\n",ans);
	return 0;
}