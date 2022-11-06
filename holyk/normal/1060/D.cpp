#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');return p?-w:w;
}
inline bool smin(int&x,const int&y){return x>y?x=y,1:0;}
inline bool smax(int&x,const int&y){return x<y?x=y,1:0;}
const int N=1e5+5;
typedef pair<int,int>pii;
int n,a[N],b[N];
int main(){
	n=read();
	REP(i,1,n)a[i]=read(),b[i]=read();
	sort(a+1,a+1+n),sort(b+1,b+1+n);
	ll ans=0;
	REP(i,1,n)ans+=max(a[i],b[i])+1;cout<<ans;
	return 0;
}