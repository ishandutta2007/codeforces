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
const int maxn=200004;
const int mod=1000000007,inf=1201201201;

class segment_tree{
#define mid ((l+r)>>1)
private:
	int s,w[maxn<<2],tag[maxn<<2],ql,qr;
	inline void pushdown(int p) {
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		w[p<<1]+=tag[p],w[p<<1|1]+=tag[p];
		tag[p]=0;
	}
	inline void update(int p,int l,int r) {
		if(l>=ql&&r<=qr) return ++w[p],++tag[p],void();
		pushdown(p);
		if(ql<=mid) update(p<<1,l,mid);
		if(qr>mid) update(p<<1|1,mid+1,r);
		w[p]=std::max(w[p<<1],w[p<<1|1]);
	}
	inline std::pair<int,int> query(int p,int l,int r) {
		if(l==r) return std::make_pair(l,w[p]);
		pushdown(p);
		if(w[p<<1|1]>w[p<<1]) return query(p<<1|1,mid+1,r);
		else return query(p<<1,l,mid);
	}
public:
	inline void build(int siz) {s=siz,memset(w,0,sizeof(w)),memset(tag,0,sizeof(tag));}
	inline void update(int l,int r) {ql=l,qr=r,update(1,1,s);}
	inline std::pair<int,int> query() {return query(1,1,s);}
#undef mid
}sgt;

struct s{int b,d;}p[maxn];
int val[maxn],cnt;
signed main()
{P_INIT();
	int n;
	fin>>n;
	for(rgi i=1;i<=n;++i) fin>>p[i].b>>p[i].d,val[++cnt]=p[i].b,val[++cnt]=p[i].d;
	std::sort(val+1,val+1+cnt),cnt=std::unique(val+1,val+1+cnt)-val-1;
	sgt.build(cnt);
	for(rgi i=1;i<=n;++i) sgt.update(std::lower_bound(val+1,val+1+cnt,p[i].b)-val,std::lower_bound(val+1,val+1+cnt,p[i].d)-val-1);
	std::pair<int,int> ans=sgt.query();
	fout<<val[ans.first]<<' '<<ans.second;
	return 0;
}
// ----------------------------
// by imzzy