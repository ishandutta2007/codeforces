#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i) 
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=300010;
ll n,x,y,ans;
signed main(){
	for(scanf("%lld",&n);n--;){
		scanf("%lld%lld",&x,&y);
		ans=x>y?x+y:y-y%x/2;
		printf("%lld\n",ans);
	}
	return 0;
}