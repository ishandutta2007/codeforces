#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010;
ll a[N],b[N],p[N],n,ans;
signed main(){
	scanf("%lld",&n);
	FOR(i,1,n)scanf("%lld%lld",a+i,b+i),p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y){return a[x]-b[x]>a[y]-b[y];});
	FOR(i,1,n)ans+=a[p[i]]*(i-1)+b[p[i]]*(n-i);
	printf("%lld",ans);
	return 0;
}