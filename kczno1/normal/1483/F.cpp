//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1e6+5;
int ch[N][26],fail[N],fir[N],dep[N],dfn[N],en[N],tot=1;
vector<int> son[N];
void dfs(int x){
	static int tot=0;
	dfn[x]=++tot;
	for(auto y:son[x]){
		if(!fir[y])fir[y]=fir[x];
		dfs(y);
	}
	en[x]=tot;
}
namespace BIT{
int c[N];
vector<int>tmp;
void add(int x,int w){
	tmp.push_back(x);
	for(int i=x;i<N;i+=i&-i)c[i]+=w;
}
void clear(int x){
	for(int i=x;i<N;i+=i&-i)c[i]=0;
}
void clear(){
	for(auto x:tmp)clear(x);
	tmp.clear();
}
int query(int x){
	int ans=0;
	for(int i=x;i;i-=i&-i)ans+=c[i];
	return ans;
}
int query(int l,int r){
	return query(r)-query(l-1);
}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	vector<string> str(n);
	for(auto &s:str){
		cin>>s;
		int x=1;
		for(auto &j:s){
			j-='a';
			if(!ch[x][j]){
				ch[x][j]=++tot;
				dep[tot]=dep[x]+1;
			}
			x=ch[x][j];
		}
		fir[x]=x;
	}		
	rep(j,0,25)ch[0][j]=1;
	deque<int> q;
	q.push_back(1);
	while(!q.empty()){
		int x=q.front();q.pop_front();
		int f=fail[x];
		son[f].push_back(x);
		rep(j,0,25){
			int y=ch[x][j];
			if(!y)ch[x][j]=ch[f][j];
			else {fail[y]=ch[f][j];q.push_back(y);}
		}
	}
	fir[1]=1;
	dfs(1);
	//rep(i,1,tot)printf("%d%c",fail[i]," \n"[i==tot]);

	int ans=0;
	for(auto s:str){
		int n=s.size();
		vector<int> p(n);
		int x=1;
		rep(i,0,n-1){
			x=ch[x][s[i]];
			p[i]=fir[x];
		}
		p[n-1]=fir[fail[p[n-1]]];
		vector<int> mn(n);
		mn[n-1]=N;
		per(i,n-2,0)mn[i]=min(mn[i+1],i+1-dep[p[i+1]]+1);
		x=1;
		rep(i,0,n-1){
			x=ch[x][s[i]];
			while(x>1&&i-dep[x]+1<mn[i])x=fail[x];
			if(dep[x]==n)x=fail[x];
			BIT::add(dfn[fir[x]],1);
		}
		sort(p.begin(),p.end(),[&](int x,int y){return dep[x]>dep[y];});
		for(auto x:p){
			if(BIT::query(dfn[x],en[x])==0){
				BIT::add(dfn[x],1);
				++ans;
			}
		}
		BIT::clear();
	}
	cout<<ans<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/