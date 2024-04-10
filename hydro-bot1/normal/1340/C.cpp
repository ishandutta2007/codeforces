// Hydro submission #6290f22837e0de7afd3a1c93@1653666345399
#include<deque>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db double
#define gc getchar
#define pc putchar
#define U unsigned
#define ll long long
#define ld long double
#define ull unsigned long long
#define Tp template<typename _T>
#define Me(a,b) memset(a,b,sizeof(a))
Tp _T mabs(_T a){ return a>0?a:-a; }
Tp _T mmax(_T a,_T b){ return a>b?a:b; }
Tp _T mmin(_T a,_T b){ return a<b?a:b; }
Tp void mswap(_T &a,_T &b){ _T tmp=a; a=b; b=tmp; return; }
Tp void print(_T x){ if(x<0) pc('-'),x=-x; if(x>9) print(x/10); pc((x%10)+48); return; }
#define EPS (1e-7)
#define INF (0x7fffffff)
#define LL_INF (0x7fffffffffffffff)
#define maxn 10039
#define maxm 1039
#define MOD
#define Type int
#ifndef ONLINE_JUDGE
//#define debug
#endif
using namespace std;
Type read(){
	char c=gc(); Type s=0; int flag=0;
	while((c<'0'||c>'9')&&c!='-') c=gc(); if(c=='-') c=gc(),flag=1;
	while('0'<=c&&c<='9'){ s=(s<<1)+(s<<3)+(c^48); c=gc(); }
	if(flag) return -s; return s;
}
int n,m,g,r,a[maxn],f[maxn][maxm]; ll ans,tmp;
struct JTZ{ int fir,sec; }; deque<JTZ> q;
#define mp(a,b) (JTZ){a,b}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(); m=read(); int i,now; JTZ cur; for(i=1;i<=m;i++) a[i]=read(); g=read(); r=read();
	sort(a+1,a+m+1); Me(f,-1); f[1][0]=0; q.push_back(mp(1,0));
	while(!q.empty()){
		cur=q.front(); q.pop_front();
		if(cur.fir>1){
			now=a[cur.fir]-a[cur.fir-1]+cur.sec;
			if(now<g) if(f[cur.fir-1][now]<0)
				f[cur.fir-1][now]=f[cur.fir][cur.sec],q.push_front(mp(cur.fir-1,now));
			if(now==g) if(f[cur.fir-1][0]<0)
				f[cur.fir-1][0]=f[cur.fir][cur.sec]+1,q.push_back(mp(cur.fir-1,0));
		}
		if(cur.fir<m){
			now=a[cur.fir+1]-a[cur.fir]+cur.sec;
			if(now<g) if(f[cur.fir+1][now]<0)
				f[cur.fir+1][now]=f[cur.fir][cur.sec],q.push_front(mp(cur.fir+1,now));
			if(now==g) if(f[cur.fir+1][0]<0)
				f[cur.fir+1][0]=f[cur.fir][cur.sec]+1,q.push_back(mp(cur.fir+1,0));
		}
	} ans=LL_INF;
	for(i=0;i<g;i++) if(f[m][i]>=0){
		tmp=(ll)f[m][i]*(g+r)+i;
		if(!i&&f[m][i]) tmp-=r;
		ans=mmin(tmp,ans);
	} print(ans==LL_INF?-1:ans); return 0;
}