#include <bits/stdc++.h>
using namespace std;

string s,t;
int n,m,i,j,sum;

bool check(string st)
{
	int i,sum=0;
	for (i=0;i<n;i++)
	{
		if (st[i]=='(') sum++; else sum--;
		if (sum<0) return 0;
	}
	
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>s;
	if (n&1)
	{
		puts("No");
		return 0;
	}
	for (i=0;i<n;i++)
	{
		if (s[i]=='(') sum++; else sum--;
	}
	if (sum)
	{
		puts("No");
		return 0;
	}
	
	t=s;
	int l=-1,r=-1;
	for (i=0;i<n;i++)
	{
		if (s[i]=='(') r=i; else if (l==-1) l=i;
	}
	
	{
		t=s;
		t.erase(t.begin()+l);
		t.push_back(')');
		if(check(t))
		{
			puts("Yes");
			return 0;
		}
	}
	
	{
		t=s;
		t.erase(t.begin()+r);
		t.insert(t.begin(),'(');
		if(check(t))
		{
			puts("Yes");
			return 0;
		}
	}
	
	puts("No");
	return 0;
}