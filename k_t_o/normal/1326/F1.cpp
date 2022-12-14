#pragma GCC optimize("Ofast")
#pragma GCC target("avx") 
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

#define N 20
#define M 505
#define MO 

int d,e,n,mp[N][N],A[M][N],B[M][N],vv[N],g[N],f[N],h[N],_O,O,op,_op,ss;
char s[N];
ll Ans[150050];

inline void sol()
{
	F(i,1,n)vv[i]=0;
	F(i,1,O)vv[h[i]]=1;
	
	F(i,1,O)f[i]=h[i];
	_O=0;F(i,1,n)if(!vv[i])g[++_O]=i;
	
	F(i,0,op)F(j,1,n)A[i][j]=0;
	do {
		ss=0;F(i,2,O)if(mp[f[i]][f[i-1]])ss+=1<<(i-2);
		++A[ss][f[O]];
	}while(next_permutation(f+1,f+O+1));
	F(i,0,_op)F(j,1,n)B[i][j]=0;
	do {
		ss=0;F(i,2,_O)if(mp[g[i]][g[i-1]])ss+=1<<(i-2);
		++B[ss][g[1]];
	}while(next_permutation(g+1,g+_O+1));
	
	F(i,0,op){
		F(k,1,O)if(A[i][f[k]]){
			F(j,0,_op){
				e=i+(j<<O);
				F(w,1,_O){
					if(mp[f[k]][g[w]])d=e+(1<<(O-1)); else d=e;
					Ans[d]+=A[i][f[k]]*B[j][g[w]];
				}
			}
		}
	}
}

void dfs(int p, int tt)
{
	if(p>n){
		if(tt!=O)return;
		
		sol();
		
		return;
	}
	dfs(p+1,tt);
	h[tt+1]=p;
	dfs(p+1,tt+1);
}

inline void _Sol_()
{
	read(n);
	F(i,1,n){
		scanf("%s",s+1);
		F(j,1,n)mp[i][j]=s[j]==49;
	}
	
	
//	int _T=clock();
	
	O=n/2; _O=n-O; op=(1<<(O-1))-1; _op=(1<<(_O-1))-1; 
	dfs(1,0);
	int o=(1<<(n-1))-1;
	F(i,0,o)pri_(Ans[i]);
	
//	cerr<<endl;
//	cerr<<clock()-_T<<endl;
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}
/*
14
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
000000000000000000000000
*/