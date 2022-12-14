#include <stdio.h>
#include <vector>

std::vector<int> ans;
void func(int s, int t)
{
	if(s>t) return;
	if(s==t)
	{
		ans.push_back(s);
		return;
	}
	ans.push_back(s);
	ans.push_back(t);
	func(s+1,t-1);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int start = 1;
	while(start+b<=a)
	{
		func(start,start+b);
		start+=(b+1);
	}
	if(start<=a) func(start,a);
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}