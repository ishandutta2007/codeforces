#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=201000;
int n,m;
char s[maxn],t[maxn];
int nxt[26][maxn];
int f[2][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
int main(){
	n=read();m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=0;i<26;++i)
		nxt[i][n]=n;
	for(int i=n-1;~i;--i){
		for(int j=0;j<26;++j)
			nxt[j][i]=nxt[j][i+1];
		nxt[s[i+1]-'a'][i]=i+1;
	}
	for(int i=1,p=0;i<=m;++i){
		p=nxt[t[i]-'a'][p];
		f[0][i]=p;
	}
	for(int i=0;i<26;++i)
		nxt[i][1]=1;
	for(int i=2;i<=n+1;++i){
		for(int j=0;j<26;++j)
			nxt[j][i]=nxt[j][i-1];
		nxt[s[i-1]-'a'][i]=i-1;
	}
	for(int i=m,p=n+1;i;--i){
		p=nxt[t[i]-'a'][p];
		f[1][i]=p;
	}
	int ans=0;
	for(int i=1;i<m;++i)
		ans=max(ans,f[1][i+1]-f[0][i]);
	printf("%d\n",ans);
	return 0;
}