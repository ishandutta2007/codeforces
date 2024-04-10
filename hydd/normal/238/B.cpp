#include<bits/stdc++.h>
using namespace std;
int n,h,a[110000],p[110000];
int main(){
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y)->bool{ return a[x]<a[y];});
	int ans1=a[p[n]]+a[p[n-1]]-(a[p[1]]+a[p[2]]);
	int ans2=max(a[p[n]]+a[p[n-1]],a[p[n]]+a[p[1]]+h)-min(a[p[1]]+a[p[2]]+h,a[p[2]]+a[p[3]]);
	printf("%d\n",min(ans1,ans2));
	for (int i=1;i<=n;i++)
		if (ans1>ans2&&i==p[1]) putchar('1'),putchar(' ');
		else putchar('2'),putchar(' ');
	return 0;
}