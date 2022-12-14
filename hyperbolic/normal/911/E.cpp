#include <stdio.h>
#include <vector>
int ans[200010],temp[200010],x[200010];
void swap(int L, int R)
{
	if(L>R) return;
	for(int i=L;i<=R;i++) temp[i] = ans[R+L-i];
	for(int i=L;i<=R;i++) ans[i] = temp[i];
}

std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	
	int p = 1;
	for(int i=1;i<=b;i++)
	{
		if(!V.empty() && V.back()<x[i])
		{
			printf("-1");
			return 0;
		}
		
		V.push_back(x[i]);
		while(!V.empty())
		{
			if(V.back()==p)
			{
				p++;
				V.pop_back();
			}
			else break;
		}
	}
	for(int i=b+1;i<=a;i++)
	{
		if(V.empty()) V.push_back(a);
		else V.push_back(V.back()-1);
		x[i] = V.back();
		while(!V.empty())
		{
			if(V.back()==p)
			{
				p++;
				V.pop_back();
			}
			else break;
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
}