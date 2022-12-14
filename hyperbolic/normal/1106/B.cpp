#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
std::pair<int,int> z[100010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.first==B.first) A.second>B.second;
	return A.first>B.first;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) z[i] = std::make_pair(y[i],i);
	std::sort(z+1,z+a+1,cmp);
	int p = a;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(x[c]>=d)
		{
			printf("%lld\n",(long long int)d*y[c]);
			x[c] -= d;
		}
		else
		{
			long long int ans = (long long int)x[c]*y[c];
			d -= x[c];
			x[c] = 0;
			while(p>=1)
			{
				if(x[z[p].second]>=d)
				{
					ans += (long long int)d*y[z[p].second];
					x[z[p].second] -= d;
					printf("%lld\n",ans);
					goto u;
				}
				else
				{
					ans += (long long int)x[z[p].second]*y[z[p].second];
					d -= x[z[p].second];
					x[z[p].second] = 0;
					p--;
				}
			}
			printf("0\n");
			u:;
		}
	}
}