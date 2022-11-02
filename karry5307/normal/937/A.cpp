#include<bits/stdc++.h>
using namespace std;
int cnt,num;
set<int>s;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>num;
		if(num!=0)
		{
			s.insert(num);
		}
	}
	set<int>::iterator iter;
	cnt=0;
	for(iter=s.begin();iter!=s.end();iter++)
	{
		cnt++;	
	}
	cout<<cnt;
}