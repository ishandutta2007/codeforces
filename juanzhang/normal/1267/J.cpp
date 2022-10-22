#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int a[N],s[N],n,k,t;
vector<int>v;
void check(int x,int y)
{
	if((y-x%y)%y<=(x+y-1)/y)
		v.push_back(y);
}
void zyb(int x)
{
	v.clear();
	int m=sqrt(x);
	for(int i=1;i<=m;i++)
		v.push_back(i);
	for(int i=0;i<=m;i++)
	{
		int y=x+i;
		for(int j=1;j*j<=y;j++)
			if(y%j==0)
				check(x,j),check(x,y/j);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(auto i:v)
		s[i]++;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=s[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		k=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				k++;
				zyb(a[i]);
			}
		}	
		for(int i=n;i>=1;i--)
		{
			int sum=0;
			if(s[i]>=k)
			{
				for(int j=1;j<=n;j++)
					sum+=(a[j]+i-1)/i;
				printf("%d\n",sum);
				break;
			}
		}
	}
	return 0;
}