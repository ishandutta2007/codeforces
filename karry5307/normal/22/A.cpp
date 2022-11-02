#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
map<int,bool>mp;//STL
int cnt,num;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>num;
		if(mp[num]==0)
		{
			mp[num]=1;
			q.push(num);
		}
		else
		{
			continue;
		}
	}
	if(q.size()==1)
	{
		cout<<"NO";
		return 0;
	}
	q.pop();
	cout<<q.top();
}