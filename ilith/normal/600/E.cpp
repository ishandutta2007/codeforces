#include<bits/stdc++.h>
#define int long long 
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
int n,u,v;
int fa[N],c[N],m[N],sum[N];
vector<int>a[N];
int son[N],siz[N],s[N],g[N];
void dfs1(int x){
	siz[x]=1;
	for(rgi i=0;i<a[x].size();++i){
		int to=a[x][i];
		if(to!=fa[x]){
			fa[to]=x,dfs1(to),siz[x]+=siz[to];
			if(siz[to]>siz[son[x]])son[x]=to;
		}
	}
	g[son[x]]=1;
}
inline void add(int x,int pos){
	++s[x];
	if(s[x]==m[pos])sum[pos]+=x;
	if(s[x]>m[pos])m[pos]=s[x],sum[pos]=x;
}
void addval(int x,int f,int w){
	if(w)add(c[x],f);
	else --s[c[x]];
	for(rgi i=0;i<a[x].size();++i){
		int to=a[x][i];
		if(to!=fa[x])addval(to,f,w);
	}
}
void dfs2(int x){
	for(rgi i=0;i<a[x].size();++i){
		int to=a[x][i];
		if(to!=fa[x]&&to!=son[x])dfs2(to);// 
	}
	if(son[x])dfs2(son[x]),m[x]=m[son[x]],sum[x]=sum[son[x]];// 
	add(c[x],x);
	for(rgi i=0;i<a[x].size();++i){
		int to=a[x][i];
		if(to!=fa[x]&&to!=son[x])addval(to,x,1);
	}
	if(!g[x])addval(x,x,0);// 
}
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(c[i]);
	for(rgi i=1;i<n;++i)read(u,v),a[u].push_back(v),a[v].push_back(u);
	dfs1(1),dfs2(1);
	for(rgi i=1;i<=n;++i)write(sum[i],' ');
    return 0;
}