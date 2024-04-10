#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<char> V;
char x[100010];
int a;
void func(int s, int t)
{
	for(int i=a;i>=1;i--)
	{
		if((x[i]-'0')%3==1 && s>=1) s--;
		else if((x[i]-'0')%3==2 && t>=1) t--;
		else V.push_back(x[i]);
	}
	if(V.size()==0)
	{
		printf("-1");
		return;
	}
	
	while(V.size()>=2 && V.back()=='0') V.pop_back();
	std::reverse(V.begin(),V.end());
	for(int i=0;i<V.size();i++) printf("%c",V[i]);
}

int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	if(a==1)
	{
		if((x[1]-'0')%3==0) printf("%c",x[1]);
		else printf("-1");
		return 0;
	}
	
	int count0 = 0, count1 = 0, count2 = 0, count3 = 0;
	for(int i=2;i<=a;i++)
	{
		if(x[i]=='0') count0++;
		else
		{
			int t = (x[i]-'0');
			if(t%3==1) count1++;
			if(t%3==2) count2++;
			if(t%3==0) count3++;
		}
	}
	
	int s = count1+2*count2 + (x[1]-'0');
	
	if(s%3==0) func(0,0);
	else if(s%3==1)
	{
		if(count1>=1) func(1,0);
		else if(count2>=2)
		{
			if((x[1]-'0')%3==1)
			{
				if(x[2]=='0') func(0,2);
				else func(1,0);
			}
			else func(0,2);
		}
		else if(count2==1) func(0,2);
		else func(1,0);
	}
	else
	{
		if(count2>=1) func(0,1);
		else if(count1>=2)
		{
			if((x[1]-'0')%3==2)
			{
				if(x[2]=='0') func(2,0);
				else func(0,1);
			}
			else func(2,0);
		}
		else if(count1==1) func(2,0);
		else func(0,1);
	}
}