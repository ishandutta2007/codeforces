#include <stdio.h>
#include <set>

int x[100010];
std::set<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int s = 0, t = 0;
	int control = 0;
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(control==1)
		{
			if(s==x[i]);
			else if(S.find(x[i])!=S.end())
			{
				t = x[i];
				control = 0;
				S.clear();
			}
			else
			{
				count++;
				S.insert(s);
				s = x[i];
			}
		}
		else
		{
			if(x[i]==s);
			else if(x[i]==t);
			else
			{
				if(s==t)
				{
					count++;
					s = x[i];
				}
				else
				{
					count++;
					S.insert(s);
					S.insert(t);
					s = x[i];
					control = 1;
				}
			}
		}
	}
	printf("%d",count);
}