#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
typedef pair<int,int> pii;
vector<int>res;
inline void solve(int n){
	if(!n)return;
	int t;
	for(ri i=sqrt(n*2)+1;i;--i){
		if((ll)i*(i-1)/2<=n){
			t=i;
			break;
		}
	}
	res.push_back(t);
	solve(n-t*(t-1)/2);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		res.clear();
		solve(read());
		sort(res.begin(),res.end());
		cout<<1;
		for(ri i=0,pre=0,up=res.size();i<up;++i){
			for(ri j=1;j<=res[i]-pre;++j)cout<<3;
			cout<<7;
			pre=res[i];
		}
		puts("");
	}
	return 0;
}