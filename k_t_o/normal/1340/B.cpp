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

#define N 
#define MO 

char op[10][8] = {
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011",
};
int n,k,fl,o,d[2005][10],f[2005][2005];
char s[2304][10];
inline void _Sol_()
{
	read(n);read(k);
	F(i,1,n)scanf("%s",s[i]);
	F(i,1,n){
		F(j,0,9){
			fl=o=0;
			F(k,0,6){
				if(s[i][k]!=op[j][k]){
					++o;
					if(s[i][k]=='1')fl=-1;
				}
			}
			if(fl)d[i][j]=-1;else d[i][j]=o;
		}
	}
	f[n+1][0]=1;
	dF(i,n,1){
		F(w,0,k){
			F(j,0,9)if(d[i][j]!=-1&&w>=d[i][j]&&f[i+1][w-d[i][j]]){
				f[i][w]=1;break;
			}
		}
	}
	if(!f[1][k]){
		puts("-1");return;
	}
	F(i,1,n){
		dF(j,9,0)if(d[i][j]!=-1&&k>=d[i][j]){
			if(f[i+1][k-d[i][j]]){
				prin(j),k-=d[i][j];
				break;
			}
		}
	}
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}