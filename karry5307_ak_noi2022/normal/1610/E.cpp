#include<cstdio>
#include<algorithm>

using namespace std;

int a[300000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=n-1;
		for(int i=n;i>=1;i--)
		{
			if(i!=1&&a[i]==a[i-1])continue;
			int j=i;while(j+1<=n&&a[j+1]==a[i])j++;int cnt=j-i+1;
			while(j<=n){j=lower_bound(a+j+1,a+n+1,2*a[j]-a[i])-a;if(j<=n)cnt++;}
			ans=min(ans,n-cnt);
		}
		printf("%d\n",ans);
	}
}