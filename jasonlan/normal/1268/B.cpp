#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long cnt[2];
int main(){
	scanf("%d",&n);
	for(register int i=1,x;i<=n;++i){
		scanf("%d",&x);
		cnt[i&1]+=x>>1;
		cnt[!(i&1)]+=x-(x>>1);
	}
	printf("%lld",min(cnt[1],cnt[0]));
	return 0;
}