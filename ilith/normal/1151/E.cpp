#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010;
ll n,a[N];
ll ans;
ll calc(ll x,ll y){
	if(x>y)swap(x,y);
	return x*(n-y+1);
}
signed main(){
	scanf("%lld",&n);
	FOR(i,1,n)scanf("%lld",a+i),ans+=calc(a[i],a[i]);
	FOR(i,1,n-1)ans-=calc(a[i],a[i+1]);
	printf("%lld",ans);
	return 0;
}