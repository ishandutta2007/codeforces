#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
#ifdef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
#endif
	int t;scanf("%d",&t);while(t--)ac();
	return 0;
}
inline ll gcd(const ll &a,const ll &b){return b?gcd(b,a%b):a;}
inline void ac(){
	int n;ll k,a,b,g=0ll;
	scanf("%d%lld%lld",&n,&k,&a);
	while(--n){scanf("%lld",&b);g=gcd(b-a,g);}
	if(g&&(k-a)%g)puts("NO");else puts("YES");
}