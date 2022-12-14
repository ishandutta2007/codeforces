#include <stdio.h>
#include <set>

std::set<int> S;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) if(x[i]%2==1) x[i] += x[i]%10;
		int max = x[1];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]%10==0)
			{
				S.insert(x[i]);
				continue;
			}
			
			int b = x[i];
			if(b<max) b += ((max-b)/20 * 20);
			while(b<max) b += b%10;
			S.insert(b);
		}
		
		int C = 0;
		while(S.size()>=2 && C <= 5*a)
		{
			int min = *(S.begin());
			S.erase(min);
			S.insert(min+min%10);
			C++;
		}
		if(S.size()==1) printf("Yes\n");
		else printf("No\n");
	}
}