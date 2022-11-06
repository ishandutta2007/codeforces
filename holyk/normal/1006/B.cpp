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
const int N=2005;
int n,k,a[N],p[N],v[N];
inline bool cmp(int i,int j){return a[i]>a[j];}
int main(){
	n=read(),k=read();
	REP(i,1,n)a[i]=read(),p[i]=i;
	sort(p+1,p+1+n,cmp);
	sort(p+1,p+k+1);
	int ans=0;
	REP(i,1,k)ans+=a[p[i]];
	cout<<ans<<endl;
	REP(i,1,k-1)printf("%d ",p[i]-p[i-1]);
	printf("%d\n",n-p[k-1]);
	return 0;
}