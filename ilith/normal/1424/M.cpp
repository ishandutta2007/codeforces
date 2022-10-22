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
using namespace std;
const int maxn=1000004,maxm=104;
const int mod=1000000007,inf=1201201201;
 
int n,k,p;
char s[maxn][maxm];
int len[maxn];
int book[28],cnt[28];
vector<int> e[28];
queue<int> q;
int topo[28],indx;
inline bool check() {
	for(rgi i=1;i<=26;++i) if(!cnt[i]) q.push(i),topo[++indx]=i;
	while(!q.empty()) {
		int t=q.front(); q.pop();
		for(rgi i=0;i<e[t].size();++i) {
			--cnt[e[t][i]];
			if(cnt[e[t][i]]==0) q.push(e[t][i]),topo[++indx]=e[t][i];
		}
	} return indx==26;
}
signed main()
{P_INIT();
	fin>>n>>k;
	for(rgi i=1;i<=n;++i) {
		fin>>p;
		for(rgi j=1;j<=k;++j) {
			scanf("%s",s[p*k+j]+1),len[p*k+j]=strlen(s[p*k+j]+1);
			for(rgi t=1;t<=len[p*k+j];++t) book[s[p*k+j][t]-'a'+1]=1;
		}
	}
	for(rgi i=1;i<n*k;++i) {
		bool flag=0;
		for(rgi j=1;j<=std::min(len[i],len[i+1]);++j)
			if(s[i][j]!=s[i+1][j]) {
				e[s[i][j]-'a'+1].push_back(s[i+1][j]-'a'+1);
				++cnt[s[i+1][j]-'a'+1];
				flag=1;
				break;
			}
		if(!flag&&len[i]>len[i+1]) {
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	if(check()) {
		for(rgi i=1;i<=26;++i) if(book[topo[i]]) fout<<char(topo[i]-1+'a');
	} else puts("IMPOSSIBLE");
	return 0;
}