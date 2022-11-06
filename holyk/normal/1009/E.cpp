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
const int N=1e6+5,M=998244353;
int n;
ll cf[N],a[N],sum,x;
inline int fpow(int x,int k){
	int ans=1;
	while(k){
		if(k&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M;k>>=1;
	}
	return ans;
}
int main(){
	n=read();cf[0]=1;
	REP(i,1,n)cf[i]=(cf[i-1]<<1)%M;
	REP(i,1,n){
		a[i]=1ll*cf[n-i]*read()%M;
		a[i]+=a[i-1];
		if(a[i]>=M)a[i]-=M;
	}
	REP(i,1,n){
		x=sum+a[i]*fpow(cf[n-i],M-2)%M;
		if(x>=M)x-=M;
		sum+=x;
		if(sum>=M)sum-=M;
	}
	cout<<x;
	return 0;
}