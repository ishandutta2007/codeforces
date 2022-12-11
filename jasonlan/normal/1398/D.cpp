#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int maxn=210;
int na,nb,nc;
int A[maxn],B[maxn],C[maxn];
long long f[maxn][maxn][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
long long dfs(int a,int b,int c){
	if(f[a][b][c])return f[a][b][c];
	if(a&&b)f[a][b][c]=max(f[a][b][c],dfs(a-1,b-1,c)+A[a]*B[b]);
	if(a&&c)f[a][b][c]=max(f[a][b][c],dfs(a-1,b,c-1)+A[a]*C[c]);
	if(b&&c)f[a][b][c]=max(f[a][b][c],dfs(a,b-1,c-1)+B[b]*C[c]);
	return f[a][b][c];
}
int main(){
	na=read();nb=read();nc=read();
	for(register int i=1;i<=na;++i)
		A[i]=read();
	for(register int i=1;i<=nb;++i)
		B[i]=read();
	for(register int i=1;i<=nc;++i)
		C[i]=read();
	sort(A+1,A+1+na);
	sort(B+1,B+1+nb);
	sort(C+1,C+1+nc);
	printf("%lld\n",dfs(na,nb,nc));
	return 0;
}