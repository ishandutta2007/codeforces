#include<bits/stdc++.h>
const int MAXN=100;
int n,ans;
int a[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i+=2)
		ans+=a[i+1]-a[i];
	printf("%d\n",ans);
	return 0;
}