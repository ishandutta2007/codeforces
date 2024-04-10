#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=5e4+5;
int n,q,x,ds,ans,tot,d;
int a[N],fa[N],dfn[N],ens[N];
int id[N],st[20],en[20];
int da[N],dep[N];
__m256i _ida[N/8+5],_ti[N/8+5];
int *ida=(int*)_ida,*ti=(int*)_ti;
vector<int>e[N];
void dfs(int x){
	dfn[x]=++ds;
	da[ds]=a[x];
	dep[ds]=dep[dfn[fa[x]]]+1;
	for(int i:e[x])dfs(i);
	ens[x]=ds;
}
const ll low32=(1LL<<32)-1;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	fo(i,1,n)cin>>a[i];
	fo(i,2,n)cin>>fa[i],e[fa[i]].pb(i);
	dfs(1);
	fo(i,1,n)id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return dep[x]<dep[y]||dep[x]==dep[y]&&x<y;});
	fo(i,1,n){
		int x=id[i];
		ida[i]=da[x];
		en[dep[x]]=i;
		if(!st[dep[x]])st[dep[x]]=i;
	}
	fo(o,1,q){
		cin>>x;
		ans=0;tot=0;
		fo(i,dep[dfn[x]],11)
			if(st[i]<=en[i]){
				int l=lower_bound(id+st[i],id+en[i]+1,dfn[x])-id;
				int r=upper_bound(id+st[i],id+en[i]+1,ens[x])-id-1;
				if(l<=r){
					int t=0;
					++r;
//					cerr<<l<<" "<<r<<endl;
					for(;(l&7)&&l<r;++l){
						bool judge=ti[l]<=o;
						t+=judge;
						ti[l]+=(o+ida[l]-ti[l])*judge;
					}
					if(l<r){
						for(;r&7;){
							bool judge=ti[--r]<=o;
							t+=judge;
							ti[r]+=(o+ida[r]-ti[r])*judge;
						}
						l>>=3;r>>=3;
						
						__m256i _o1=_mm256_set_epi32(o+1,o+1,o+1,o+1,o+1,o+1,o+1,o+1),_t=_mm256_set_epi32(0,0,0,0,0,0,0,0);
						__m256i zero=_t,one=_mm256_set_epi32(1,1,1,1,1,1,1,1),_o=_mm256_sub_epi32(_o1,one);
						fo(i,l,r-1){
							__m256i judge=_mm256_cmpgt_epi32(_o1,_ti[i]);
							_t=_mm256_add_epi32(_t,_mm256_and_si256(judge,one));
							_ti[i]=_mm256_add_epi32(_ti[i],_mm256_and_si256(_mm256_sub_epi32(_mm256_add_epi32(_o,_ida[i]),_ti[i]),judge));
						}
						fo(i,0,3)t+=(_t[i]>>32)+(_t[i]&low32);
					}
					tot+=t;
					ans+=t*i;
				}
			}
		ans-=tot*dep[dfn[x]];
		printf("%d %d\n",ans,tot);
	}
}