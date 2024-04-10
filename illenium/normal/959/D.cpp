#include<stdio.h>
using namespace std;
bool bj[2000005];

int main()
{
	int n,a,now=2,ans;
	scanf("%d",&n);
	bool flag=false;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		ans=now;
		if(!flag&&a>ans)
			ans=a;
		while(bj[ans])
			++ans;
		printf("%d ",ans);
		if(ans>a)
			flag=true;
		for(int j=now;j*j<=ans;++j)
		{
			if(ans%j)
				continue;
			while(ans%j==0)
				ans/=j;
			if(!bj[j]) 
				for(int t=j;t<2000005;t+=j) 
					bj[t]=true;
		}
		if(ans!=1)
			for(int j=ans;j<2000005;j+=ans)
				bj[j]=true;
		while(bj[now])
			++now;
	}
	return 0;
}