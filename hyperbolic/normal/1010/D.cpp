#include <stdio.h>
#include <vector>

int type[1000010];
int value[1000010];
int ans[1000010];
std::vector<int> V[1000010];

char x[10];
int getValue(int k)
{
	if(type[k]==5) return value[k];
	if(value[k]!=-1) return value[k];
	
	else
	{
		if(type[k]==1) // AND
		{
			int s1 = getValue(V[k][0]);
			int s2 = getValue(V[k][1]);
			return value[k] = (s1&s2);
		}
		if(type[k]==2) // OR
		{
			int s1 = getValue(V[k][0]);
			int s2 = getValue(V[k][1]);
			return value[k] = (s1|s2);
		}
		if(type[k]==3) // XOR
		{
			int s1 = getValue(V[k][0]);
			int s2 = getValue(V[k][1]);
			return value[k] = (s1^s2);
		}
		if(type[k]==4) // NOT
		{
			int s1 = getValue(V[k][0]);
			return value[k] = (!s1);
		}
	}
}
void makeValue(int k, int color)
{
	if(type[k]==5)
	{
		ans[k] = color;
		return;
	}
	for(int i=0;i<V[k].size();i++) makeValue(V[k][i],color);
}

void func(int k, int s, int t) // if s, value 0 if t, value 1
{
	if(type[k]==1) // AND
	{
		int s1 = getValue(V[k][0]);
		int s2 = getValue(V[k][1]);
		
		if(s2==0) makeValue(V[k][0],s);
		else func(V[k][0],s,t);
		if(s1==0) makeValue(V[k][1],s);
		else func(V[k][1],s,t);
	}
	else if(type[k]==2) // OR
	{
		int s1 = getValue(V[k][0]);
		int s2 = getValue(V[k][1]);
		
		if(s2==1) makeValue(V[k][0],t);
		else func(V[k][0],s,t);
		if(s1==1) makeValue(V[k][1],t);
		else func(V[k][1],s,t);
	}
	else if(type[k]==3) //XOR
	{
		int s1 = getValue(V[k][0]);
		int s2 = getValue(V[k][1]);
		
		
		if(s2==0) func(V[k][0],s,t);
		else func(V[k][0],t,s);
		if(s1==0) func(V[k][1],s,t);
		else func(V[k][1],t,s);
	}
	else if(type[k]==4) //NOT
	{
		func(V[k][0],t,s);
	}
	else //IN
	{
		if((1-value[k])==s) ans[k] = 0;
		else ans[k] = 1;
		return;
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=a;i++) value[i] = -1;
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%s",x+1);
		if(x[1]=='A')
		{
			type[i]=1;
			scanf("%d%d",&b,&c);
			V[i].push_back(b);
			V[i].push_back(c);
		}
		else if(x[1]=='O')
		{
			type[i]=2;
			scanf("%d%d",&b,&c);
			V[i].push_back(b);
			V[i].push_back(c);
		}
		else if(x[1]=='X')
		{
			type[i]=3;
			scanf("%d%d",&b,&c);
			V[i].push_back(b);
			V[i].push_back(c);
		}
		else if(x[1]=='N')
		{
			type[i]=4;
			scanf("%d",&b);
			V[i].push_back(b);
		}
		else //IN
		{
			type[i]=5;
			scanf("%d",&b);
			value[i] = b;
		}
	}
	func(1,0,1);
	for(int i=1;i<=a;i++) if(type[i]==5) printf("%d",ans[i]);
}