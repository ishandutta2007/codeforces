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
int n;
int ind[1007];
int main(){
	n=read();
	REP(i,2,n){
		int x=read(),y=read();
		++ind[x],++ind[y];
	}
	int ans=0;
	REP(i,1,n)if(ind[i]==1)++ans;
	cout<<ans<<endl;
	return 0;
}