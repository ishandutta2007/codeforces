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
const int N=3e5+7;
int n;
struct node{
	int x,y,id;
	node(int a=0,int b=0,int c=0):x(a),y(b),id(c){}
}a[N];
inline bool cmp(node a,node b){return a.x<b.x||a.x==b.x&&a.y>b.y;} 
int main(){
	n=read();
	REP(i,1,n){
		int x=read(),y=read(); 
		a[i]=node(x,y,i);
	}
	sort(a+1,a+1+n,cmp);
	REP(i,1,n-1)if(a[i].y>=a[i+1].y)return printf("%d %d\n",a[i+1].id,a[i].id),0;
	puts("-1 -1");
	return 0;
}