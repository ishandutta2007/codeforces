#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2010;
int n,m;
long long ans;
int col[maxn][maxn];
int u[maxn][maxn],d[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline int getmp(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch-'a';
}
bool cmp(int x1,int y1,int x2,int y2){
	return col[x1][y1]==col[x2][y2];
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j){
			col[i][j]=getmp();
			u[i][j]=cmp(i,j,i-1,j)?u[i-1][j]+1:1;
		}
	for(register int i=n;i;--i)
		for(register int j=1;j<=m;++j)
			d[i][j]=cmp(i,j,i+1,j)?d[i+1][j]+1:1;
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=m;++j){
			if(cmp(i,j,i,j-1))
				l[i][j]=min(min(u[i][j],d[i][j]),l[i][j-1]+1);
			else l[i][j]=1;
		}
		for(register int j=m;j;--j){
			if(cmp(i,j,i,j+1))
				r[i][j]=min(min(u[i][j],d[i][j]),r[i][j+1]+1);
			else r[i][j]=1;
		}
		for(register int j=1;j<=m;++j)
			ans+=min(l[i][j],r[i][j]);
	}
	printf("%lld\n",ans);
	return 0;
}