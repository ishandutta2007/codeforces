#include<bits/stdc++.h>
#define x first
#define y second
#define rnd (rand()<<15|rand())
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f,N=2e5+10;
const ll INFL=0x3f3f3f3f3f3f3f3f;
template<class T>inline bool chkmin(T &x,const T &y){return y<x?x=y,1:0;}
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
int n,m,A[N];
ll pos[N],L[N],R[N];
int main(){
//	int cas;
//	scanf("%d",&cas);
//	while(cas--){
		scanf("%d%d",&n,&m);
		FOR(i,1,n)scanf("%d",&A[i]);
		FOR(i,1,m){
			scanf("%lld",&pos[i]);
			pos[i]+=100;
		}
		sort(pos+1,pos+1+m);
		pos[0]=-INFL;
		pos[m+1]=INFL;
		for(int p=0,i=1;i<=n;++i){
			while(p<m&&pos[p+1]<=i*100)
				++p;
			L[i]=pos[p];
		}
		for(int p=m+1,i=n;i>=1;--i){
			while(p>1&&pos[p-1]>=i*100)
				--p;
			R[i]=pos[p];
		}
		ll ans=0,res=0;
		for(int p=0,i=1;i<=n;++i){
			ll md=200*i-L[i];
			if(p<i-1){
				p=i-1;
				res=0;
			}
			while(p<n&&L[i]==L[p+1]&&100*(p+1)-md<R[p+1]-100*(p+1)){
				++p;
				res+=A[p];
			}
			chkmax(ans,res);
			res-=A[i];
		}
		printf("%lld\n",ans);
//	}
	return 0;
}