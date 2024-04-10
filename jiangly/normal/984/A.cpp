#include<bits/stdc++.h>
const int MAXN=1000;
int n;
int a[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	printf("%d\n",a[(n+1)/2]);
	return 0;
}