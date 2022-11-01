#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,a[500005],mi=1e9+7,mx;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		mi=min(mi,a[i]); 
	}
	printf("%d\n",mx-mi-n+1);
	return 0;
}