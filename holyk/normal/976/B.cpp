#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
ll n,m,k;
int main(){
	cin>>n>>m>>k;++k;
	if(k<=n)return cout<<k<<" 1"<<endl,0;
	k-=n;--m;
	ll a=2ll*m;
	ll x=(k-1)/a+1,y=(k-1)%a+1;
	if(y<=m)cout<<n-(x-1)*2ll<<' '<<y+1<<endl;
	else cout<<n-(x-1)*2ll-1<<' '<<2ll*m-y+2<<endl;
}