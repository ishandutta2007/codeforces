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
int n,m;
ll ans=0;
int main(){
	n=read(),m=read();
	while(m--){
		int x=read(),d=read();
		if(d>=0)ans+=1ll*d*n*(n-1)/2+1ll*n*x;
		else ans+=1ll*d*((n>>1)+1)*(n>>1)/2+1ll*d*(n-(n>>1)-1)*(n-(n>>1))/2+1ll*n*x;
	}
	printf("%.15lf",(double)ans/n);
	return 0;
}