#include<bits/stdc++.h>
namespace P_TEMPLATE{
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
	setbuf(stdout,NULL),setbuf(stdin,NULL);
	#endif
}}using namespace P_TEMPLATE;
// ----------------------------
// #define int ll
// using namespace std;
const int maxn=1000004;
const int mod=1000000007,inf=1201201201;

int sum[maxn];
bool isnp[maxn]; int pr[maxn],cntp;
inline void init() {
	sum[1]=1;
	for(rgi i=2;i<maxn;++i) {
		if(!isnp[i]) {
			pr[++cntp]=i,++sum[i];
			if((ll)i*i<maxn) --sum[i*i];
		}
		for(rgi j=1;j<=cntp&&i*pr[j]<maxn;++j) {
			isnp[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	} for(rgi i=2;i<maxn;++i) sum[i]=sum[i-1]+sum[i];
}
signed main()
{P_INIT();
	init();
	rgi t,n; fin>>t;
	while(t--) fin>>n,fout<<sum[n]<<endl;
	return 0;
}
// ----------------------------
// by imzzy