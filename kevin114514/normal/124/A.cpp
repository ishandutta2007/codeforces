#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,cnt=0;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		int behind=n-i,front=i-1;
		if(behind<=b&&front>=a)
			cnt++;
	}
	printf("%d",cnt);
	return 0;
}