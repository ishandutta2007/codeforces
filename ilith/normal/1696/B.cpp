#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e5+7;
int T,n,z,a[N],ans;
void solve(){
	scanf("%d",&n),ans=0;
	int cnt=0;
	FOR(i,1,n){
		scanf("%d",a+i),a[i]=!!a[i];
		if(a[i]==1&&a[i-1]==0)++cnt;
	}
	printf("%d\n",min(cnt,2));
}
int main(){
	for(scanf("%d",&T);T--;)solve();
	return 0;
}