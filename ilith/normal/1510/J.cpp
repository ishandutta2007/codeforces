#include<bits/stdc++.h>
namespace imzzy{
	typedef long long ll;
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
}using namespace imzzy;
// ----------------------------
// #define int ll
// using namespace std;
const int mod=1000000007,inf=1201201201;
const int maxn=400004,maxm=500004;

char s[maxn];
int white[maxn],black[maxn],indx=0;
int cnt,ans[maxn];
inline void pp(int i) {
	white[i]-=2;
	if(white[i]&1) ans[++cnt]=2,white[i]-=3;
	while(white[i]>0) ans[++cnt]=1,white[i]-=2;
}
inline int printaz() {
	pp(0);
	for(rgi i=1;i<=indx;++i) ans[++cnt]=black[i]+2,pp(i);
	fout<<cnt<<endl;
	for(rgi i=1;i<=cnt;++i) fout<<ans[i]<<' ';
	return 0;
}
signed main() {
	scanf("%s",s+1);
	int len=strlen(s+1);
	int p=1;
	for(;p<=len;++p) if(s[p]=='#') break; else ++white[0];
	for(;p<=len;) {
		++indx,white[indx]=-1;
		for(;p<=len;++p) if(s[p]=='_') break; else ++black[indx];
		for(;p<=len;++p) if(s[p]=='#') break; else ++white[indx];
	} ++white[indx];
// for(rgi i=0;i<=indx;++i) fout<<white[i]<<' '; fout<<endl;
// for(rgi i=1;i<=indx;++i) fout<<black[i]<<' '; fout<<endl;
	if(indx==0) {puts("0"); return 0;}
	int t=inf;
	bool flag=1;
	// puts("ababa");
	for(rgi i=0;i<=indx;++i) {
		t=std::min(t,white[i]);
		if(white[i]>0) flag=0;
	}
	if(flag) {
		fout<<indx<<endl;
		for(rgi i=1;i<=indx;++i) fout<<black[i]<<' ';
		return 0;
	}
	// puts("000");
	if(t>0) {
		flag=1;
		for(rgi i=0;i<=indx;++i) if((white[i]-1)&1) flag=0;
		if(flag) {
			for(rgi i=1;i<=white[0]/2;++i) ans[++cnt]=1;
			for(rgi i=1;i<=indx;++i) {
				ans[++cnt]=black[i]+1;
				for(rgi j=1;j<=white[i]/2;++j) ans[++cnt]=1;
			}
			fout<<cnt<<endl;
			for(rgi i=1;i<=cnt;++i) fout<<ans[i]<<' ';
			return 0;
		}
	}
	// puts("111");
	if(t>1) {
		t=inf;
		for(rgi i=0;i<=indx;++i) if(white[i]!=2) t=std::min(t,white[i]);
		if(t>=4) return printaz();
		for(rgi i=0;i<=indx;++i) --white[i];
		for(rgi i=1;i<=indx;++i) ++black[i];
		t=inf;
		for(rgi i=0;i<=indx;++i) if(white[i]!=2) t=std::min(t,white[i]);
		if(t>=4) return printaz();
	}
	puts("-1");
	return 0;
}
// ----------------------------
// by imzzy