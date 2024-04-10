#include<bits/stdc++.h>
typedef long long ll,int64,LL;
const int inf=1e9;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	inline char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	inline int read_int(){
		int ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	inline char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	inline int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
namespace algo{
	template<class T>inline const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>inline const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
	template<class T>inline void swap(T&a,T&b){
		T c=a;
		a=b;
		b=c;
	}
	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	inline int sq(int x){
		return x*x;
	}
    template<class T>inline void fill(T*a,T*b,const T&c){
        for(;a!=b;*a++=c);
    }
}
using namespace algo;
const int MAXN=50;
int n,h,m;
namespace flow{
    const int MAXV=2552,MAXE=10100;
    struct edge{
        int to,next,cap;
    }e[MAXE];
    int n,s,t;
    int tot_edge;
    int head[MAXV],cur[MAXV],h[MAXV];
    void link(int u,int v,int cap){
        e[tot_edge]={v,head[u],cap};
        head[u]=tot_edge++;
        e[tot_edge]={u,head[v],0};
        head[v]=tot_edge++;
    }
    bool bfs(){
        static int q[MAXV];
        fill(h,h+n,-1);
        h[s]=0;
        int l=0,r=0;
        q[r++]=s;
        for(;l!=r;){
            int u=q[l++];
            for(int i=head[u];~i;i=e[i].next){
                int v=e[i].to,cap=e[i].cap;
                if(cap&&!~h[v]){
                    h[v]=h[u]+1;
                    if(v==t)
                        return 1;
                    q[r++]=v;
                }
            }
        }
        return 0;
    }
    int dfs(int u,int flow){
        if(u==t)
            return flow;
        int res=flow;
        for(int&i=cur[u];~i&&res;i=e[i].next){
            int v=e[i].to,cap=e[i].cap;
            if(cap&&h[v]==h[u]+1){
                int min_flow=dfs(v,min(res,cap));
                res-=min_flow;
                e[i].cap-=min_flow;
                e[i^1].cap+=min_flow;
            }
        }
        return flow-res;
    }
    int max_flow(){
        int flow=0;
        for(;bfs();){
            memcpy(cur,head,n*sizeof(int));
            int augment_flow;
            for(;(augment_flow=dfs(s,inf));)
                flow+=augment_flow;
        }
        return flow;
    }
}
void solve(){
    n=read_int();
    h=read_int();
    m=read_int();
    flow::n=n*h+m+2;
    flow::s=flow::n-2;
    flow::t=flow::n-1;
    fill(flow::head,flow::head+flow::n,-1);
    for(int i=0;i<n;++i)
        flow::link(flow::s,i*h,sq(h));
    for(int i=0;i<n;++i)
        for(int j=1;j<h;++j)
            flow::link(i*h+j-1,i*h+j,sq(h)-sq(j));
    for(int i=0;i<m;++i){
        int l,r,x,c;
        l=read_int();
        r=read_int();
        x=read_int();
        c=read_int();
        if(x==h)
            continue;
        for(int j=l-1;j<r;++j)
            flow::link(j*h+x,n*h+i,inf);
        flow::link(n*h+i,flow::t,c);
    }
    printf("%d\n",n*sq(h)-flow::max_flow());
}
int main(){
    solve();
	return 0;
}