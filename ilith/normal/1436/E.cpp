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
using namespace std;
const int mod=998244353,inf=1201201201;
const int maxn=100004;


int n,ans,a[maxn];
int root[maxn],ls[50*maxn],rs[50*maxn],rig[50*maxn],c;
void upd(int l,int r,int &cur,int las,int pos,int v){
	cur=++c;
    ls[cur]=ls[las];rs[cur]=rs[las];
	if(l==r){
        rig[cur]=v;
        return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)upd(l,mid,ls[cur],ls[las],pos,v);
	else upd(mid+1,r,rs[cur],rs[las],pos,v);
	rig[cur]=min(rig[ls[cur]],rig[rs[cur]]);//min>=l >=l
}
int ask(int cur,int l,int r,int v){
    if(!cur || l==r){
        return l;
    }
    int mid=(l+r)/2;
	if(rig[ls[cur]]<v){
        return ask(ls[cur],l,mid,v);
	}
	return ask(rs[cur],mid+1,r,v);
}
inline int query(int l,int r) {if(l>r) return -1; return ask(root[r],0,n,l);}


std::vector<int> pos[maxn];
signed main()
{P_INIT();
	fin>>n;
	for(rgi i=1;i<=n;++i) {
		fin>>a[i],pos[a[i]].push_back(i);
		upd(0,n,root[i],root[i-1],a[i]-1,i);
	}
	bool flag=1;
	for(ans=1;flag;++ans) {
		// fout<<'+'<<' '<<ans<<endl;
		int pre=1;
		flag=0;
		for(rgi i=0;i<pos[ans].size()&&!flag;++i) {
			if(query(pre,pos[ans][i]-1)==ans-1) flag=1;
			// fout<<pre<<' '<<pos[ans][i]-1<<' '<<query(pos[ans][i]-1,pre)<<endl;
			pre=pos[ans][i]+1;
		} if(query(pre,n)==ans-1) flag=1; //fout<<endl;
		// fout<<'-'<<' '<<ans<<endl;
	} fout<<ans-1;
	return 0;
}
// ----------------------------
// by imzzy