#include<bits/stdc++.h>
namespace imzzy{
	#define endl '\n'
	#define rgi register int
	typedef long long ll;
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;class fastout{private:int _num[32],_head;
	public:inline fastout&operator<<(char c){putchar(c);return*this;}
	template<typename _Tp> inline fastout&operator<<(_Tp _x){
	_Tp _k;if(_x==0){putchar('0');return *this;}if(_x<0)putchar('-'),_x=-_x;
	while(_x>0)_k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
	while(_head>0)putchar(_num[_head]),--_head;return*this;}fastout(){_head=0;}
	}fout;inline void P_INIT(){
	#ifdef D_STDOUT_UNBUFFERED
	setbuf(stdout,NULL);
	#endif
}}using namespace imzzy;
// ----------------------------
// #define int ll
// using namespace std;
const int mod=1000000007,inf=1201201201;
const int maxn=200004;

int n,x,pos;
bool book[maxn];
int a[maxn];
inline void init() {
	a[pos]=1;
	for(rgi i=pos+1;i<n;++i) a[i]=2;
	int l=0,r=n,mid;
	while(l<r) {
		book[mid=(l+r)>>1]=1;
		if(a[mid]<=1) l=mid+1;
		else r=mid;
	}
}
signed main()
{P_INIT();
	fin>>n>>x>>pos;
	init();
	ll ans=1,cnt1=0,cnt2=0;
	for(rgi i=0;i<pos;++i) if(book[i]) ++cnt1,(ans*=x-cnt1)%=mod;
	for(rgi i=pos+1;i<n;++i) if(book[i]) (ans*=n-x-cnt2)%=mod,++cnt2;
	for(rgi i=n-cnt1-cnt2-1;i>0;--i) (ans*=i)%=mod;
	fout<<ans;
	return 0;
}
// ----------------------------
// by imzzy