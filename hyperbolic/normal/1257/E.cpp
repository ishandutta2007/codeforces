#include <stdio.h>
#include <set>

std::multiset<int> S;
int check1[200010],check2[200010],check3[200010];
int left[600010],right[600010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int sum;
	
	S.clear();
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		S.insert(d);
	}
	
	sum = 0;
	for(int i=1;i<=a+b+c;i++)
	{
		if(S.find(i)!=S.end()) sum++;
		check1[i] = sum;
	}
	
	S.clear();
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		S.insert(d);
	}
	
	sum = 0;
	for(int i=1;i<=a+b+c;i++)
	{
		if(S.find(i)!=S.end()) sum++;
		check2[i] = sum;
	}
	
	S.clear();
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		S.insert(d);
	}
	
	sum = 0;
	for(int i=1;i<=a+b+c;i++)
	{
		if(S.find(i)!=S.end()) sum++;
		check3[i] = sum;
	}
	
	int ans = c>a?c:a;
	int C = check3[a+b+c];
	
	a = a+b+c;
	for(int i=1;i<=a;i++) left[i] = check1[i-1] - check2[i-1];
	for(int i=1;i<=a;i++) right[i] = check2[i] - check3[i];
	
	S.clear();
	for(int i=0;i<=a;i++) S.insert(right[i]);
	for(int i=1;i<=a;i++)
	{
		std::multiset<int> ::iterator it = S.end();
		it--;
		int val = left[i] + (*it);
		ans = ans>val+C?ans:val+C;
		it = S.find(right[i-1]);
		S.erase(it);
	}
	printf("%d",a-ans);
}