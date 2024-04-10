#include<bits/stdc++.h>
namespace imzzy{
	typedef long long ll;
	typedef unsigned long long ull;
	// #define endl '\n'
	#define endl std::endl
	#define rgi register int
	#define fout std::cout
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;
}using namespace imzzy;
// ----------------------------
// #define int ll
// using namespace std;
const ll mod=1000000007ll,inf=1000000000ll,debug=0;
const int maxn=100004,maxm=2504;

signed main(){
	// freopen("tt.in","r",stdin);
	// freopen("tt.out","w",stdout);
	fout<<"? "<<1<<' '<<1<<endl;
	int t,k;
	fin>>t;
	int l=1,r=std::min(t,(int)inf),mid,ans=0;
	while(l<=r) {
		mid=((l+r)>>1);
		fout<<"? "<<1<<' '<<mid<<endl;
		fin>>k;
		if(k+(mid-1)==t) ans=mid,l=mid+1;
		else r=mid-1;
	}
	int lx,ly,rx,ry;
	fout<<"? "<<1<<' '<<ans<<endl;
	fin>>lx,++lx;
	ly=ans;
	fout<<"? "<<inf<<' '<<1<<endl;
	fin>>k;
	rx=inf-(k-(ly-1));
	fout<<"? "<<inf<<' '<<inf<<endl;
	fin>>k;
	ry=inf-(k-(inf-rx));
	fout<<"! "<<lx<<' '<<ly<<' '<<rx<<' '<<ry<<endl;
	return 0;
}
// by imzzy
// ----------------------------