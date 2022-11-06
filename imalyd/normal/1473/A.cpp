#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
//const int MAXN=;
template<class IT>inline void cmx(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmn(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline bool bmx(IT &a,IT b){if(a<b){a=b;return true;}else return false;}
template<class IT>inline bool bmn(IT &a,IT b){if(b<a){a=b;return true;}else return false;}
inline void ac(){
	int n,d,f=1,a,mn=110,se=110;
	scanf("%d%d",&n,&d);
	while(n--){
		scanf("%d",&a);
		if(a<mn){se=mn;mn=a;}else cmn(se,a);
		if(a>d)f=0;
	}
	if(f||mn+se<=d)puts("YES");else puts("NO");
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)ac();
	return 0;
}