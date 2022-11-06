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
const int N=4e5+5;
int n,a[N],c[N];;
inline void add(int p){
	p+=n+1;
	while(p<=n+n)++c[p],p+=p&-p;
}
inline int ask(int p){
	p+=n+1;
	int ans=0;
	while(p)ans+=c[p],p-=p&-p;
	return ans;
}
inline ll solve(int x){
	ll ans=0;
	int sum=0;
	memset(c,0,sizeof c);add(0);
	REP(i,1,n){
		if(a[i]>x)++sum;else --sum;
		ans+=ask(-sum);add(-sum); 
	}
	return ans;
}
int main(){
	n=read();int m=read();
	REP(i,1,n)a[i]=read();
	cout<<solve(m)-solve(m-1);
	return 0;
}