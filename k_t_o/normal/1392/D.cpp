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

#define N 210005
#define MO 
int Ans,n,f[N][2][2];
char s[N],ss[N];
inline void _Sol_()
{
	read(n); Ans=n+10;
	scanf("%s",ss+1);
	F(i,1,n)if(ss[i]=='L')s[i]=48;else s[i]=49;
	F(a1,0,1)
	F(a2,0,1){
		F(i,0,n)
		F(j,0,1)
		F(k,0,1)f[i][j][k]=n+10;
		
		f[2][a1][a2]=(bool)(s[1]!=48+a1)+(bool)(s[2]!=48+a2);
		F(i,3,n){
			F(j,0,1)
			F(k,0,1)
			F(w,0,1){
				if(j+k+w<3&&j+k+w>0)
				chmin(f[i][k][w],f[i-1][j][k]+(bool)(s[i]!=48+w));
			}
		}
		F(j,0,1)
		F(k,0,1){
			if(j+k+a1<3&&j+k+a1>0&&k+a1+a2<3&&k+a1+a2>0)chmin(Ans,f[n][j][k]);
		}
	}
	priE(Ans);
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
4
RLRL
*/