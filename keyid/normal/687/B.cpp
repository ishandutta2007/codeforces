#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector <int> p,c;
int _max[10];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=2;i<=k;i++)
		if (k%i==0)
		{
			p.pb(i);
			int cnt=0;
			while (k%i==0)
			{
				cnt++;
				k/=i;
			}
			c.pb(cnt);
		}
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for (int j=0;j<p.size();j++)
		{
			int x=p[j],t=0;
			while (a%x==0)
			{
				t++;
				a/=x;
			}
			_max[j]=max(_max[j],t);
		}
	}
	for (int i=0;i<p.size();i++)
		if (_max[i]<c[i])
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}