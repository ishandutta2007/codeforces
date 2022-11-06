#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=2e4+7,inf=0x3f3f3f3f;
int n,k,p,a[N],f[N],g[N],v[105];
int main(){
	n=read(),k=read(),p=read();
	REP(i,1,n)a[i]=(read()+a[i-1])%p;
	memset(f,0xcf,sizeof f);f[0]=0;
	while(k--){
		memset(v,0xcf,sizeof v);v[0]=0;
		REP(i,1,n){
			g[i]=0;
			REP(j,0,p-1)
				if(v[j]>=0)smax(g[i],v[j]+(a[i]-j+p)%p);
			smax(v[a[i]],f[i]);
		}
		REP(i,1,n)f[i]=g[i];
	}
	printf("%d\n",f[n]);
	return 0;
}