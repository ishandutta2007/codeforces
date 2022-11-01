#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int n,a[111],ans;

int main()
{
	int i,j;
	
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	rep(i,n)
	{
		int f=1;
		rep(j,i-1)
		{
			if (a[i]%a[j]==0)
			{
				f=0;
			}
		}
		ans+=f;
	}
	
	cout<<ans<<endl;
	return 0;
}