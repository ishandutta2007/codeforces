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
const int N=1000;
int n,m,a[N];
void write(int x){
//	dbg("xx%d\n\n",x);
	printf("%d %d\n",x/60,x%60);
}
int main(){
	n=read(),m=read();
	REP(i,1,n){
		int x=read(),y=read();
		a[i]=x*60+y;
	}
	if(a[1]>m)return write(0),0;
	REP(i,2,n)if(a[i]-a[i-1]>=2*m+2){
		return write(a[i-1]+m+1),0;
	}
	write(a[n]+m+1);
	return 0;
}