#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
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
const int N=200010;
int n,m,fa[N],u,v,cnt,vis[N];
vector<int>a[N],s[N],r,res[2],tmp;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void link(int u,int v){a[u].pbk(v),a[v].pbk(u),fa[find(u)]=find(v+n),fa[find(v)]=find(u+n);}
int bel[N],C,s1,s2;
void chg(int a,int b,int c){
	bel[a]=bel[b]=bel[c]=++C;
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=(n<<1);++i)fa[i]=i;
	for(rgi i=1;i<=m;++i)read(u,v),link(u,v);
	for(rgi i=1;i<=n;++i){
		if(!s1)s1=find(i),s2=find(i+n);
		else if(find(i)!=s1&&find(i)!=s2)fa[find(i)]=s1,fa[find(i+n)]=s2;
	}
	for(rgi i=1;i<=n;++i)s[find(i)].pbk(i);
	for(rgi i=1;i<=(n<<1);++i){
		if(s[i].size())++cnt,r.pbk(i);
	}
	if(s[r[0]].size()%3){
		if(s[r[0]].size()%3==2)swap(r[0],r[1]);
		for(rgi k:s[r[0]]){
			if(a[k].size()<s[r[1]].size()-1)res[0].pbk(k);
		}
		for(rgi k:s[r[1]]){
			if(a[k].size()<s[r[0]].size()-1)res[1].pbk(k);
		}
		if(res[0].size()){
			int x=res[0][0];
			for(rgi k:a[x])vis[k]=1;
			for(rgi i:s[r[1]])if(!vis[i])tmp.pbk(i);
			chg(x,tmp[0],tmp[1]),tmp.clear();
		}
		else if(res[1].size()>=2){
			int x=res[1][0],y=res[1][1];
			for(rgi k:a[x])vis[k]=1;
			for(rgi i:s[r[0]])if(!vis[i])tmp.pbk(i);
			chg(x,tmp[0],tmp[1]),tmp.clear();
			memset(vis,0,sizeof vis);
			for(rgi k:a[y])vis[k]=1;
			for(rgi i:s[r[0]])if(!vis[i])tmp.pbk(i);
			chg(y,tmp[0],tmp[1]),tmp.clear();
		}
		else return puts("NO"),0;
	}
	puts("YES"),tmp.clear();
	for(rgi x:s[r[0]]){
		if(!bel[x])tmp.pbk(x);
		if(tmp.size()==3)chg(tmp[0],tmp[1],tmp[2]),tmp.clear();
	}
	for(rgi x:s[r[1]]){
		if(!bel[x])tmp.pbk(x);
		if(tmp.size()==3)chg(tmp[0],tmp[1],tmp[2]),tmp.clear();
	}
	for(rgi i=1;i<=n;++i)write(bel[i],' ');
	return 0;
}