#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
const int N=2e5+7;
int n,a,b,x[N],tt;
pii v[N];
unordered_map<ll,int> g;
map<pii,int> s;
int main(){
	n=read(),a=read(),b=read();
	ll ans=0;
	REP(i,1,n){
		x[i]=read(),v[i].X=read(),v[i].Y=read();
		if(v[i].X==0&&v[i].Y==0)continue;
		ll tmp=1ll*a*v[i].X-v[i].Y;
		pii k;
		int d=__gcd(abs(v[i].X),abs(v[i].Y));
		k.X=v[i].X/d,k.Y=v[i].Y/d;
		ans+=g[tmp]++-s[k]++;
	}
	cout<<ans*2ll;
	return 0;
}