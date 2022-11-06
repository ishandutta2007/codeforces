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
template<typename T>
inline void read(T&w){
    char c;
    while(!isdigit(c=getchar()));w=c&15;
    while(isdigit(c=getchar()))w=w*10+(c&15);
}
const int N=2e5+7;
int n,q;
ll a[N],k[N],s[N];
int main(){
	read(n);read(q);
	REP(i,1,n)read(a[i]),s[i]=s[i-1]+a[i];
	REP(i,1,q){
		read(k[i]);k[i]+=k[i-1];
		int p=upper_bound(s+1,s+1+n,k[i])-s;
		if(p==n+1){k[i]=0ll;printf("%d\n",n);
		}
		else printf("%d\n",n-p+1);
	}
	return 0;
}