#include<bits/stdc++.h>
namespace P_TEMPLATE{
	#define endl '\n'
	#define rgi register int
	typedef long long ll;
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;class fastout{private:int _num[32],_head;
	public:inline fastout&operator<<(char c){putchar(c);return*this;}
	template<typename _Tp> inline fastout&operator<<(_Tp _x){
	_Tp _k;if(_x==0){putchar('0');return *this;}if(_x<0)putchar('-'),_x=-_x;
	while(_x>0)_k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
	while(_head>0)putchar(_num[_head]),--_head;return*this;}fastout(){_head=0;}
	}fout;inline void P_INIT(){
	#ifdef D_STDOUT_UNBUFFERED
	setbuf(stdout,NULL),setbuf(stdin,NULL);
	#endif
}}using namespace P_TEMPLATE;
// ----------------------------
// #define int ll
// using namespace std;
const int maxn=200004,maxm=400004,debug=0;
const int mod=1000000007,inf=1201201201;

namespace FLOWS{
	struct EDGE{int to,w,nxt;} e[maxm<<1|1];
	int n,cnte,first[maxn+1];
	inline void init(int _n) {n=_n,cnte=-1,memset(first,-1,(n+1)*sizeof(int));}
	inline void addedge(int from,int to,int w) {e[++cnte]=(EDGE){to,w,first[from]},first[from]=cnte;}
}
namespace MAXFLOW{
	using namespace FLOWS;
	int n,s,t,ans;
	inline void init(int _n,int _s,int _t) {s=_s,t=_t,ans=0,n=_n,FLOWS::init(n);}
	inline void addedge(int from,int to,int w) {
		if(debug&1) std::cout<<"MAXFLOW::addedge "<<from<<' '<<to<<' '<<w<<endl;
		FLOWS::addedge(from,to,w),FLOWS::addedge(to,from,0);
	}
	int dep[maxn+1],cur[maxn+1],q[maxn+1];
	inline bool bfs() {
		memcpy(cur,first,(n+1)*sizeof(int));
		memset(dep,0,(n+1)*sizeof(int));
		rgi l=1,r=1,u,i; q[1]=s,dep[s]=1;
		while(l<=r) for(u=q[l++],i=first[u];~i;i=e[i].nxt)
			if(e[i].w>0&&!dep[e[i].to]) dep[e[i].to]=dep[u]+1,q[++r]=e[i].to;
		return dep[t];
	}
	int dfs(int now,int flow) {
		if(now==t) return flow; int res=0;
		for(rgi i=cur[now],to;~i;i=e[i].nxt) {
			cur[now]=i,to=e[i].to;
			if(dep[to]==dep[now]+1&&e[i].w>0)
				if((res=dfs(to,std::min(flow,e[i].w)))>0)
					{e[i].w-=res,e[i^1].w+=res; return res;}
		} return 0;
	}
	inline int work() {
		int now;
		while(bfs()) while((now=dfs(s,inf))>0) {
			ans+=now;
			if((debug>>1)&1) std::cout<<"MAXFLOW::work "<<ans<<'\n';
		} return ans;
	}
}

int n,m;
struct EDGEX{
	int w,u,v;
	inline bool operator<(const EDGEX &b) const {return w<b.w;}
} ee[maxn];
inline bool check(int p) {
	MAXFLOW::init(maxn,0,maxn-1);
	for(rgi i=1;i<=p;++i) MAXFLOW::addedge(ee[i].u,ee[i].v+100002,1);
	for(rgi i=1;i<=n;++i) MAXFLOW::addedge(0,i,1),MAXFLOW::addedge(i+100002,maxn-1,1);
	int ans=MAXFLOW::work();
	if(ans==n) return 1;
	else return 0;
}
signed main()
{P_INIT();
	fin>>n>>m;
	for(rgi i=1;i<=m;++i) fin>>ee[i].u>>ee[i].v>>ee[i].w;
	// puts("OK");
	std::sort(ee+1,ee+1+m);
	// puts("OK");
	rgi l=1,r=m,mid,ans=m;
	while(l<=r) {
		// fout<<l<<' '<<r<<' '<<mid<<endl;
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(check(ans)) fout<<ee[ans].w;
	else fout<<-1;
	return 0;
}
// ----------------------------
// by imzzy