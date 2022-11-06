#include<bits/stdc++.h>
using namespace std;
int b[105];
int main()
{
	b[0]=1;
	for(int i=1;i<=30;i++)b[i]=2*b[i-1];
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			int wz=upper_bound(b,b+31,a)-b-1;
			printf("%d ",b[wz]);
		}
		puts("");
	}
	return 0;
}