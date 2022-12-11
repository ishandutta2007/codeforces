#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010,maxnn=500010;
int n;
int mat[maxn][maxn],val[maxn<<1],fa[maxn<<1],prefa[maxn<<1];
int x[maxnn],y[maxnn],ord[maxnn],tnt;
int no[maxn],cnt;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool cmp(int a,int b){
	return mat[x[a]][y[a]]<mat[x[b]][y[b]];
}
int getf(int x){
	return fa[x]==x?x:(fa[x]=getf(fa[x]));
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			mat[i][j]=read();
			if(i==j)val[i]=mat[i][j];
			else if(i>j){
				x[++tnt]=i;y[tnt]=j;ord[tnt]=tnt;
			}
		}
	sort(ord+1,ord+1+tnt,cmp);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1,a,b;i<=tnt;++i){
		a=x[ord[i]];b=y[ord[i]];
		a=getf(a);b=getf(b);
		if(a==b)continue;
		++n;
		val[n]=mat[x[ord[i]]][y[ord[i]]];
		fa[a]=fa[b]=fa[n]=n;
		prefa[a]=prefa[b]=n;
	}
	cnt=1;
	for(int i=n-1;i;--i){
		if(val[prefa[i]]!=val[i]){
			++cnt;
			fa[i]=i;
		}
		else fa[i]=getf(prefa[i]);
	}
	printf("%d\n",cnt);
	for(int i=1,j=0;i<=n;++i)
		if(getf(i)==i){
			no[i]=++j;
			if(j>1)putchar(' ');
			printf("%d",val[i]);
		}
	printf("\n%d\n",no[n]);
	for(int i=1;i<n;++i)
		if(getf(i)==i)
			printf("%d %d\n",no[i],no[getf(prefa[i])]);
	return 0;
}