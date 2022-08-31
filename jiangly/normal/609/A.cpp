#include<bits/stdc++.h>
const int MAXN=100;
int n,m,ans;
int a[MAXN+5];
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=n;m>0;--i){
		m-=a[i];
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}