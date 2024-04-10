#include <stdio.h>
#include <set>
struct str{
	int value;
	int height;
	int number;
};
bool operator<(str a, str b)
{
	return a.value<b.value;
}
std::set<str> S;
int ans[100010];
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	str A;
	A.value = b;
	A.height = 1;
	A.number = 1;
	S.insert(A);
	for(int i=2;i<=a;i++)
	{
		scanf("%d",&b);
		str A;
		A.value = b;
		A.height = 1;
		A.number = i;
		std::set<str> ::iterator it;
		it = S.lower_bound(A);
		if(it==S.begin())
		{
			A.height = (*it).height+1;
			S.insert(A);
			ans[i] = (*it).value;
		}
		else if(it==S.end())
		{
			it--;
			A.height = (*it).height+1;
			S.insert(A);
			ans[i] = (*it).value;
		}
		else
		{
			std::set<str> ::iterator it2 = it;
			it2--;
			if(it->height>it2->height)
			{
				A.height = it->height+1;
				S.insert(A);
				ans[i] = it->value;
			}
			else
			{
				A.height = it2->height+1;
				S.insert(A);
				ans[i] = it2->value;
			}
		}
	}
	for(int i=2;i<=a;i++) printf("%d ",ans[i]);
}