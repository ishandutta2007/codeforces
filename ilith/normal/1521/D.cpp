#include<bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
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
int n,t,u,v;
int low[N],siz[N],key[N],fa[N];
vector<int>a[N];
pii ch[N];
inline void link(int u,int v){
	a[u].push_back(v),a[v].push_back(u);
}
void dfs(int x,int f){
	siz[x]=1,low[x]=x,fa[x]=f;
	int son=0;
	for(rgi to:a[x]){
		if(to==f)continue;
		dfs(to,x),siz[x]+=siz[to];
		if(key[x]&&!key[to])key[to]=1,ch[to]=pii(to,low[to]);
		else if(!key[to]){
			++son;
			if(low[x]!=x)key[x]=1,ch[x]=pii(low[x],low[to]);
			else low[x]=low[to];
		}
	}
	siz[x]-=son;
	if(x==1&&son<2)key[1]=1,ch[1]=pii(1,low[1]);
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i){
			low[i]=siz[i]=key[i]=fa[i]=0;
			ch[i]=pii(0,0);
			a[i].clear();
		}
		for(rgi i=1;i<n;++i)read(u,v),link(u,v);
		dfs(1,0),write(siz[1]-1,'\n');
		int now=0;
		for(rgi i=1;i<=n;++i){
			if(key[i]){
				if(!now)now=ch[i].se;
				else write(i,' ',fa[i],' ',now,' ',ch[i].fi,'\n'),now=ch[i].se;
			}
		}
	}
	return 0;
}