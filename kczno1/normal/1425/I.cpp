#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
#include<immintrin.h>
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

const int N=5e4+10,M=20;
 
int n,q;
int a[N],_a[N],dfn[N],rev[N],pos,val[N],siz[N],_dep[N],dep[N];
int m[M],id[M][N];
int v[M][N],tim[M][N];
 
struct Edge{
  int v,nxt;
}c[N];
int front[N],edge_cnt;
 
inline void addedge(int u,int v){
  c[++edge_cnt]=(Edge){v,front[u]};
  front[u]=edge_cnt;
}
 
void dfs(int x){
  dfn[x]=++pos,rev[pos]=x;
  a[pos]=_a[x],siz[x]=1;
  dep[pos]=_dep[x];
  for(int i=front[x];i;i=c[i].nxt){
    int v=c[i].v;
    _dep[v]=_dep[x]+1;
    dfs(v);
    siz[x]+=siz[v];
  }
}
 
int main(){
#ifdef kcz 
  freopen("1.in","r",stdin);
#endif
	cin>>n>>q;
  for(int i=1;i<=n;++i)_a[i]=read()-1;
  for(int i=2;i<=n;++i)addedge(read(),i);
  dfs(1);
  for(int i=1;i<=n;i++){
    int u=dep[i];
    // printf("%d = %d\n",i,dep[i]);
    ++m[u];
    id[u][m[u]]=i;
    tim[u][m[u]]=a[i];
  }
  for(int t=1;t<=q;++t){
	  int x=read();
    int L=dfn[x],R=L+siz[x]-1,l,r;
    int a1=0,a2=0;
    // printf(">> L=%d R=%d\n",L,R);
	rep(d,0,10)
	{
      l=std::lower_bound(id[d]+1,id[d]+m[d]+1,L)-id[d]-0;              
      r=std::upper_bound(id[d]+1,id[d]+m[d]+1,R)-id[d]-1;              
      if(l<=r){                                                            
        int cnt=0;
		for(;u64(v[d]+l)%32&&l<=r;++l)
          if(v[d][l]<t){                                                  
            v[d][l]=t+tim[d][l];                                           
            cnt++;                                                         
          }
__m256i sum=_mm256_setzero_si256(),_t=_mm256_set_epi32(t,t,t,t,t,t,t,t);  
		for(;l+7<=r;l+=8)
		{
			__m256i nv=*(__m256i*)(v[d]+l);
			__m256i nt=*(__m256i*)(tim[d]+l);
			__m256i c=_mm256_cmpgt_epi32(_t,nv);
			sum=_mm256_add_epi32(sum,c);
			*(__m256i*)(v[d]+l)=_mm256_xor_si256(nv,_mm256_and_si256(_mm256_xor_si256(nv,_mm256_add_epi32(nt,_t)),c));	
			//rep(j,l,l+3)
			//if(tim[d][j]==1&&v[d][j]!=2)
			//{
				//cerr<<l<<" "<<j<<" "<<v[d][j]<<endl;
			//}
		}
		rep(i,0,7)cnt-=((int*)&sum)[i];                                                                 
		//if(d==1)
			//cerr<<v[d][21]<<" "<<tim[d][21]<<endl;
		for(;l<=r;++l)
          if(v[d][l]<t){                                                  
			  //if(t>1)
			  	//cerr<<l<<" "<<tim[d][l]<<" "<<v[d][l]<<endl;
            v[d][l]=t+tim[d][l];                                           
            cnt++;                                                         
          } 
        a1+=cnt*d;                                                         
        a2+=cnt;                                                           
      }
	}
    printf("%d %d\n",a1-a2*_dep[x],a2);
  }
  return 0;
}