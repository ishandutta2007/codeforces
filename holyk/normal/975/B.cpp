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
ll a[18],b[18];
ll solve(int p){
	if(a[p]==0)return 0;
	int x=a[p]/14,y=a[p]%14;
	REP(i,1,14)b[i]=i!=p?a[i]+x:x;
	int t=p;
	while(y--){
		if(++t==15)t=1;++b[t];
	}
	ll ans=0;
	REP(i,1,14)if(!(b[i]&1))ans+=b[i];
	//REP(i,1,14)dbg("%d ",b[i]);dbg("\n");
	return ans;
}
int main(){
	REP(i,1,14)a[i]=read();
	ll ans=0; 
	REP(i,1,14)smax(ans,solve(i));
	cout<<ans;
	return 0;
}