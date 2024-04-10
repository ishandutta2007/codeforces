#include<bits/stdc++.h>
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
int n;
int c[N];
int st[N],ed[N];
vector<int>a[N];
int fa[N],dx[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int vis[N],cnt;
signed main(){
	read(n);
	for(rgi i=1;i<n;++i)read(st[i],ed[i]),a[st[i]].push_back(ed[i]),a[ed[i]].push_back(st[i]);
	for(rgi i=1;i<=n;++i)read(c[i]),fa[i]=i,dx[i]=1;
	for(rgi i=1;i<n;++i){
		if(c[st[i]]!=c[ed[i]])continue;
		int fx=find(st[i]),fy=find(ed[i]);
		if(fx!=fy)fa[fx]=fy,dx[fy]+=dx[fx];
	}
	for(rgi i=1;i<=n;++i)vis[find(i)]=1;
	for(rgi i=1;i<=n;++i){
		cnt=n;
		for(rgi to:a[i]){
			int k=find(to);
			if(vis[k])cnt-=dx[k],vis[k]=0;
		}
		if(cnt<=vis[find(i)]){
			puts("YES");
			write(i);
			return 0;
		}
		for(rgi to:a[i]){
			int k=find(to);
			if(!vis[k])vis[k]=1;
		}
	}
	puts("NO");
	return 0;
}