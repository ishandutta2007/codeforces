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
int n,a,b,d[100007];
int main(){
	n=read(),a=read(),b=read();
	int s=0;
	REP(i,1,n)d[i]=read(),s+=d[i];
	double x=1.0*d[1]*a/b;
	sort(d+2,d+1+n);
	int ans=0;
	if(s>x)DEC(i,n,2){++ans;if((s-=d[i])<=x)break;}
	printf("%d\n",ans);
	return 0;
}