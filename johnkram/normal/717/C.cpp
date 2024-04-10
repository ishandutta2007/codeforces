#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define P 10007
#define MAXN 100005
int n,i,a[MAXN],ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)ans=(ans+a[i]%P*a[n-i+1])%P;
	cout<<ans<<endl;
	return 0;
}