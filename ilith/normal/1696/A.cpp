#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e5+7;
int T,n,z,a[N],ans;
void solve(){
	scanf("%d%d",&n,&z),ans=0;
	FOR(i,1,n){
		scanf("%d",a+i);
		ans=max(ans,a[i]|z);
	}
	printf("%d\n",ans);
}
int main(){
	for(scanf("%d",&T);T--;)solve();
	return 0;
}