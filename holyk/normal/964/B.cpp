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
int n,a,b,c,t;
int main(){
	cin>>n>>a>>b>>c>>t;
	int ans=0;
	REP(i,1,n){
		int x=read(),mx=-0x3f3f3f3f;
		REP(j,x,t)smax(mx,a-b*(j-x)+(j-x)*c);
	//	if(mx==0xcfcfcfcf)mx=a-b*(t-x);
	
		ans+=mx;
	}
	cout<<ans;
	return 0;
}