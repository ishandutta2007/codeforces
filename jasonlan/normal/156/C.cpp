#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110,maxt=2610,mod=1e9+7;
int n,tnt;
int f[maxn][maxt];
char s[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qmod(int x){
	return x>=mod?x-mod:x;
}
int dfs(int l,int t){
	if(t<0)return 0;
	if(!l)return !t;
	if(f[l][t]>=0)return f[l][t];
	f[l][t]=0;
	for(register int i=1;i<=26;++i)
		f[l][t]=qmod(f[l][t]+dfs(l-1,t-i));
	return f[l][t];
}
int main(){
	memset(f,-1,sizeof(f));
	for(register int T=read();T;--T){
		scanf("%s",s+1);
		n=strlen(s+1);
		tnt=0;
		for(register int i=1;i<=n;++i)
			tnt+=s[i]-'a'+1;
		printf("%d\n",qmod(dfs(n,tnt)+mod-1));
	}
    return 0;
}