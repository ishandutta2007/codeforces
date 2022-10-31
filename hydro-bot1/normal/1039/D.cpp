// Hydro submission #61891d9b07d7abb3c5820e8f@1636375964258
#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
inline int max(int a,int b) {return a>b?a:b;}
const int N=2e5+10;
int n,t=0,linkk[N],a[N],cnt=0,p[N],f[N],d[N],q,ans[N];
struct node {
	int y,next;
}e[N*2];
void insert(int x,int y) {
	e[++t].y=y;
	e[t].next=linkk[x];
	linkk[x]=t;
}
void dfs(int x,int father) {
	for (int i=linkk[x];i;i=e[i].next) {
		int y=e[i].y;
		if (y==father) continue;
		dfs(y,x);
	}
	d[++cnt]=x; p[x]=father;
}
int solve(int k) {
	int r=0;
	for (int i=1;i<=n;i++) f[i]=1;
	for (int i=1;i<=n;i++) {
		int x=d[i];
		if(p[x]&&(~f[p[x]])&&(~f[x]))
			if(f[x]+f[p[x]]>=k) r++,f[p[x]]=-1;
			else f[p[x]]=max(f[p[x]],f[x]+1);
	}
	return r;
}
int main() {
	n=read();
	q=sqrt(n*log(n)/log(2));
	for (int i=1;i<n;i++) {
		int x,y;
		x=read(); y=read();
		insert(x,y);
		insert(y,x);
	}
	dfs(1,0);
	ans[1]=n;
	for (int i=2;i<=q;i++) ans[i]=solve(i);
	int l,r;
	for (int i=q+1;i<=n;i=l+1) {
		l=i,r=n; int t=solve(i),mid;
		for (;l<r;solve(mid)^t?r=mid-1:l=mid)
			mid=l+r+1>>1;
		for (int j=i;j<=l;j++) ans[j]=t;
	}
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}