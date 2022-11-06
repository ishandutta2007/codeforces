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
const int M=1e9+9;
int n,a,b,k;
char s[100005];
inline int fpow(int x,int k){
	int ans=1;
	while(k){
		if(k&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M;k>>=1;
	}
	return ans;
}
int main(){
	n=read(),a=read(),b=read(),k=read();
	scanf("%s",s);
	ll one=0,ans=0;
	int m=n%k;
	REP(i,n/k*k,n){
		if(s[i%k]=='+')ans=(ans+1ll*fpow(a,n-i)*fpow(b,i)%M)%M;
		else ans=(ans-1ll*fpow(a,n-i)*fpow(b,i)+M)%M;
	}
	REP(i,0,k-1){
		if(s[i]=='+')one=(one+1ll*fpow(a,n-i)*fpow(b,i)%M)%M;
		else one=(one-1ll*fpow(a,n-i)*fpow(b,i)%M+M)%M;
	}
	int f=1ll*fpow(fpow(a,k),M-2)*fpow(b,k)%M;
//	REP(i,1,n/k)ans=(ans+one*fpow(f,i-1))%M;
	if(f==1)ans=(ans+one*(n/k))%M;
	else ans=(ans+one*(1ll-fpow(f,n/k)+M)%M*fpow(1ll-f+M,M-2)+M)%M;
	cout<<ans;
	
	return 0;
}