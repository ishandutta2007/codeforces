#include <stdio.h>
#include <vector>
std::vector<int> V[200010];
int count[200010];
int func(int k)
{
	int s=0;
	if(V[k].size()==0) return count[k]=1;
	for(int i=0;i<V[k].size();i++)
	{
		s+=func(V[k][i]);
	}
	return count[k]=s;
}
int minimum1(int k);
int minimum2(int k);
int maximum2(int k);
int maximum1(int k)
{
	int min=0,a;
	if(V[k].size()==0)
	{
		return 1;
	}
	a = count[V[k][0]]+1-minimum2(V[k][0]);
	min=a;
	for(int i=1;i<V[k].size();i++)
	{
		a = count[V[k][i]]+1-minimum2(V[k][i]);
		min=min<a?min:a;
	}
	return min;
}
int minimum1(int k)
{
	int min=0,a;
	if(V[k].size()==0)
	{
		return 1;
	}
	a = count[V[k][0]]+1-maximum2(V[k][0]);
	min=a;
	for(int i=1;i<V[k].size();i++)
	{
		a = count[V[k][i]]+1-maximum2(V[k][i]);
		min=min<a?min:a;
	}
	return min;
}
int maximum2(int k)
{
	int sum=0,a;
	if(V[k].size()==0)
	{
		return 1;
	}
	a = count[V[k][0]]+1-minimum1(V[k][0]);
	sum=(a-1);
	for(int i=1;i<V[k].size();i++)
	{
		a = count[V[k][i]]+1-minimum1(V[k][i]);
		sum+=(a-1);
	}
	return sum+1;
}
int minimum2(int k)
{
	int sum=0,a;
	if(V[k].size()==0)
	{
		return 1;
	}
	a = count[V[k][0]]+1-maximum1(V[k][0]);
	sum+=(a-1);
	for(int i=1;i<V[k].size();i++)
	{
		a = count[V[k][i]]+1-maximum1(V[k][i]);
		sum+=(a-1);
	}
	return sum+1;
}
int main()
{
	int a,b,c,i;
	scanf("%d",&a);
	for(i=1;i<a;i++)
	{
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
	}
	func(1);
	printf("%d %d",count[1]+1-maximum1(1),count[1]+1-maximum2(1));
}