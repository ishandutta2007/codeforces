#include<bits/stdc++.h>
namespace xiong_6{
	typedef long long ll;
	typedef unsigned long long ull;
	#define endl '\n'
	#define rgi register int
	#define fout std::cout
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;
}using namespace xiong_6;
// ----------------------------
// #define int ll
// using namespace std;
const int mod=998244353,inf=1201201201;
const int maxn=300004,maxm=3004;

std::string s;
int ans[maxn];
signed main() {
	// freopen("tt.in","r",stdin);
	// freopen("tt.out","w",stdout);
	rgi t,n;
	fin>>t;
	while(t--) {
		fin>>n;
		std::cin>>s;
		int pre=0;
		for(rgi i=1;i<=n+1;++i) ans[i]=0;
		for(rgi i=1;i<=n+1;++i)
			if(i==n+1||(i&1)^(s[i-1]=='R')) {
				for(rgi j=pre+1;j<=i;++j) if(j&1)
					ans[j]=i-pre;
				pre=i;
			}
		pre=0;
		for(rgi i=1;i<=n+1;++i)
			if(i==n+1||(i&1)^(s[i-1]=='L')) {
				for(rgi j=pre+1;j<=i;++j) if(!(j&1))
					ans[j]=i-pre;
				pre=i;
			}
		for(rgi i=1;i<=n+1;++i) fout<<ans[i]<<' '; fout<<endl;
	} return 0;
}
// ----------------------------
// by imzzy