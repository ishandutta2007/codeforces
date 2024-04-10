#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7;
int n,p,a[N],s[N];
int main(){
	n=read(),p=read();
	REP(i,1,n)a[i]=read(),s[i]=(s[i-1]+a[i])%p;
	int ans=0;
	REP(i,1,n)ans=max(ans,s[i]+(s[n]-s[i]+p)%p);
	cout<<ans<<endl;
	return 0;
}