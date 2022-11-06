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
int n,m,p;
pii t[100005];
void out(){
	puts("Possible");
	REP(i,1,m)printf("%d %d\n",t[i].X,t[i].Y);
	exit(0); 
}
int main(){
	cin>>n>>m;
	if(m<n-1)goto ed;
	REP(i,1,n)REP(j,i+1,n)
	if(__gcd(i,j)==1){
		t[++p]=make_pair(i,j);
		if(p==m)out();
	}
	ed:puts("Impossible");
	return 0;
}