#include<stdio.h>
#include <set>

char x[1000010],y[1000010];
std::set<int> S1,S2;
void func1(int k)
{
	std::set<int> ::iterator it1 = S1.lower_bound(k);
	if(it1==S1.end()) return;
	std::set<int> ::iterator it2 = S2.lower_bound((*it1));
	if(it2==S2.end()) return;
	int C = (*it2);
	S1.erase(it1);
	S2.erase(it2);
	func1(C);
}

void func2(int k)
{
	std::set<int> ::iterator it2 = S2.lower_bound(k);
	if(it2==S2.end()) return;
	std::set<int> ::iterator it1 = S1.lower_bound((*it2));
	if(it1==S1.end()) return;
	int C = (*it1);
	S2.erase(it2);
	S1.erase(it1);
	func2(C);
}

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0'&&y[i]=='1') S1.insert(i);
		if(x[i]=='1'&&y[i]=='0') S2.insert(i);
	}
	if(S1.size()!=S2.size())
	{
		printf("-1");
		return 0;
	}
	
	int count = 0;
	while(!S1.empty()||!S2.empty())
	{
		std::set<int> ::iterator it1 = S1.begin();
		std::set<int> ::iterator it2 = S2.begin();
		if((*it1)<(*it2)) func1(0);
		else func2(0);
		count++;
	}
	printf("%d",count);
}