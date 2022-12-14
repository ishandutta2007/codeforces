#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			P[i]=std::make_pair(d,c);
		}
		std::sort(P+1,P+b+1);
		int start = 0;
		int state = 0;
		for(int i=1;i<=b;i++)
		{
			if(P[i].first<start)
			{
				printf("NO\n");
				goto u;
			}
			if(P[i].first==start)
			{
				if(P[i].second==1)
				{
					if(state==-1) state = 0;
					else
					{
						printf("NO\n");
						goto u;
					}
				}
				else
				{
					if(state==1) state = 0;
					else
					{
						printf("NO\n");
						goto u;
					}
				}
				continue;
			}
			
			int t = P[i].first-1-start;
			t/=2;
			t*=2;
			start += t;
			
			if(start==P[i].first-2)
			{
				if(state==-1)
				{
					start++;
					state = 1;
				}
				else if(state==0) start++;
				else
				{
					start++;
					state = -1;
				}
			}
			if(start==P[i].first-1)
			{
				if(state==-1)
				{
					if(P[i].second==1)
					{
						printf("NO\n");
						goto u;
					}
					else
					{
						start++;
						state = 0;
					}
				}
				else if(state==0)
				{
					start++;
					if(P[i].second==1) state = 1;
					else state = -1;
				}
				else
				{
					if(P[i].second==2)
					{
						printf("NO\n");
						goto u;
					}
					else
					{
						start++;
						state = 0;
					}
				}
			}
		}
		if(state==0) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}