#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
long long ans=0;
int a[M],c[M],s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&c[i]);
		ans+=c[i];c[i]=a[i]+c[i];
	}
	sort(a+1,a+n+1);
	sort(c+1,c+n+1);
	for(int i=2;i<=n;++i)ans+=max(0,a[i]-c[i-1]);
	printf("%lld\n",ans);
	return 0;
}