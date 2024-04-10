//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 2105000

char _p[N],s[N],t[N];
int u,l,r,m,o,n,L,R,p[N];

void manacher() { 

//	static int p[N];

//	F(i,0,n)p[i]=0;

	int id = 0, pos = 0, x = 0;
	for (int i = 1; i <= n; ++i) {
		if (pos > i) x = std::min(p[id * 2 - i], pos - i);
			else x = 1;
		while (s[i - x] == s[i + x]) ++x;
		if (i + x > pos) pos = i + x, id = i;
		p[i] = x;  // 
	}
}
/*
int main() {
	while (scanf("%s", t + 1), t[1] != 'E') {
		m = strlen(t + 1);
		s[n = 0] = '!';
		for (int i = 1; i <= m; ++i) {
			s[++n] = '#';
			s[++n] = t[i];
		}
		s[++n] = '#';
		s[n + 1] = '?';
		manacher();
		int ans = 0;
		for (int i = 1; i <= n; ++i)if (p[i] > ans) ans = p[i];
		printf("Case %d: %d\n", ++T, ans - 1);  // ans-1 
	}
}
*/
inline void _Sol_()
{
	scanf("%s",t+1); o=strlen(t+1);
	u=1; while(u<=(o+1)/2&&t[u]==t[o-u+1])++u;
	if(u>(o+1)/2){
		printf("%s\n",t+1); return;
	}
	l=u; r=o-u+1;
	m=0; F(i,l,r)_p[++m]=t[i];
		
	s[n=0] = '!';
		for (int i = 1; i <= m; ++i) {
			s[++n] = '#';
			s[++n] = _p[i];
		}
		s[++n] = '#';
		s[n + 1] = '?';
	manacher();
	int ans = 0, fl=0;
	for (int i = 1; i <= n; ++i)if (p[i]-1> ans) {
		if(i%2==0){
			u=i/2;
			L=u-p[i]/2+1;
			R=u+p[i]/2-1;
			if(L==1){
				fl=0;
				ans=p[i]-1;
				continue;
			}
			if(R==r-l+1){
				fl=1;
				ans=p[i]-1;
				continue;
			}
			continue;
		}
		u=i/2; //left
		L=u-(p[i]-3)/2;
		R=u+(p[i]-1)/2;
		if(L==1){
				fl=0;
				ans=p[i]-1;
				continue;
			}
			if(R==r-l+1){
				fl=1;
				ans=p[i]-1;
				continue;
			}
	}
	
	F(i,1,l-1)printf("%c",t[i]);
	
	
	if(!fl){
		F(i,l,l+ans-1)printf("%c",t[i]);
	} else 
	F(i,r-ans+1,r)printf("%c",t[i]);
	
	
	F(i,r+1,o)printf("%c",t[i]);puts("");
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
abcdfdcecba
*/