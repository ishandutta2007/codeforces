#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) {fprintf(stderr,__VA_ARGS__);fflush(stderr);}
namespace IO{
	const int l=1<<20;
	char buf[l],*s,*t,c;bool f;
	inline void gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			c=s==t?EOF:*s++;
		}else c=*s++;
	}
	template<class I>inline void gi(I &x){
		x=0;f=false;gc();while(c<'0'||c>'9'){if(c=='-')f=true;gc();}
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}if(f)x=-x;
	}
	char buf0[20];int a;
	template<class I>inline void pi(I x){
		if(x<0){putchar('-');x=-x;}
		do buf0[++a]=x%10+48;while(x/=10);
		while(a)putchar(buf0[a--]);
		putchar(' ');
	}
};
using IO::gi;
using IO::pi;
inline void ac();
int main(){
#ifdef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
#endif
	int t;gi(t);while(t--)ac();
	return 0;
}
const int MAXN=500005;
vector<int>T[MAXN];
set<int>S,E[MAXN];
inline void dfs(const int &v){
	//Find a spanning tree of G'
	//ERR("DFS v=%d\n",v);
	S.erase(v);
	int u=0;
	set<int>::iterator s;
	for(;;){
		if((s=S.upper_bound(u))==S.end())break;
		u=*s;
		if(E[v].count(u))continue;
		if(S.count(u)){
			//ERR("T + %d %d\n",v,u);
			T[v].push_back(u);
			T[u].push_back(v);
			dfs(u);
		}
	}
}
set<int>A[MAXN];
int I[MAXN],P[MAXN],Q[MAXN];
inline void ac(){
	int n,m,i,v,u,t=0,f;
	gi(n);gi(m);
	rep(v,1,n)E[v].clear();
	rep(i,1,m){
		gi(v);gi(u);
		//ERR("+ %d %d\n",v,u);
		E[v].insert(u);
		E[u].insert(v);
	}
	u=0;
	rep(v,1,n){
		if(E[v].size()==n-1)P[v]=Q[v]=++t;
		else S.insert(u=v);
	}
	if(u){
		//ERR("u=%d\n",u);
		vector<int>::iterator e,ee;
		rep(v,1,n)T[v].clear();
		rep(v,1,n)if(E[v].size()!=n-1&&T[v].empty())dfs(v);
		rep(v,1,n)A[v].clear();
		rep(v,1,n)I[v]=0;
		rep(v,1,n)if(!(T[v].empty()||I[v])){
			f=1;
			for(e=T[v].begin(),ee=T[v].end();e!=ee;++e){
				if(I[u=*e]){if(f)f=u;}else{
					if(f){f=0;I[v]=v;}
					I[u]=v;A[v].insert(u);
				}
			}
			//ERR("v=%d f=%d\n",v,f);
			if(f){
				u=I[f];
				if(u==f){I[v]=f;A[f].insert(v);}
				else{
					if(A[u].size()==1){
						I[u]=I[f]=I[v]=f;
						A[u].clear();
						A[f].insert(v);
						A[f].insert(u);
					}else{
						A[u].erase(f);
						I[f]=I[v]=v;
						A[v].insert(f);
					}
				}
			}
		}
		set<int>::iterator a,aa;
		rep(v,1,n)if(I[v]==v){
			P[v]=++t;Q[v]=t+A[v].size();
			for(a=A[v].begin(),aa=A[v].end();a!=aa;++a){
				Q[u=*a]=t;P[u]=++t;
			}
			//ERR("STAR %d | ",v);
			//for(a=A[v].begin(),aa=A[v].end();a!=aa;++a)ERR("%d ",*a);
			//ERR("\n");
		}
	}
	//rep(v,1,n)printf("%d ",P[v]);putchar('\n');
	//rep(v,1,n)printf("%d ",Q[v]);putchar('\n');
	rep(v,1,n)pi(P[v]);putchar('\n');
	rep(v,1,n)pi(Q[v]);putchar('\n');
}