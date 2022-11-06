
#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
typedef long long ll;
int main(){
	ll a=read(),b=read(),c=read(),ans=c*2,t=min(a,b);
	ans+=t*2,a-=t,b-=t;
	if(a)++ans;
	if(b)++ans;
	cout<<ans;
	return 0;
}