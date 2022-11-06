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
const int N=5e5+7,inf=0x3f3f3f3f;
int n,k,p,a[N],f[N],g[N];
int c[105];
inline void add(int s,int x){
	++s;while(s<=p)smin(c[s],x),s+=s&-s;
}
inline int ask(int s){
	int ans=inf;
	++s;while(s)smin(ans,c[s]),s-=s&-s;
	return ans;
}
int main(){
	n=read(),k=read(),p=read();
	REP(i,1,n)a[i]=(a[i-1]+read())%p;
	memset(f,0x3f,sizeof f);f[0]=0;
	REP(j,1,k){
		REP(i,1,p)c[i]=inf;
		int mn=f[j-1];
		add(a[j-1],f[j-1]);
		REP(i,j,n){
			g[i]=min(mn+1,ask(a[i]));
			add(a[i],f[i]);
			smin(mn,f[i]);
		}
		REP(i,j,n)f[i]=g[i];
	}
	printf("%d\n",f[n]*p+a[n]);
	return 0;
}