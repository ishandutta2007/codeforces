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
int n,m,a[N],s[N];
unordered_map<int,int>p;
int main(){
	n=read(),m=read();
	bool f=0;
	ll ans=0;++p[0];
	REP(i,1,n){
		int x=read()-m;if(!x)f=1;else a[i]=x/abs(x);
		a[i]+=a[i-1];
		if(f)ans+=p[a[i]]+p[a[i]-1];
		else ++p[a[i]];
	}
	cout<<ans;
	return 0;
}