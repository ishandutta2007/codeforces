#include<bits/stdc++.h>
using namespace std;
multiset<int> MS1,MS2,delta;
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		MS1.insert(x);
		MS2.insert(-x);
	}
	int last=-1;
	for(multiset<int>::iterator it=MS1.begin();it!=MS1.end();it++)
	{
		if(last!=-1)
			delta.insert(last-*it);
		last=*it;
	}
	cout<<-(*MS1.begin()+*MS2.begin())+*delta.begin()<<endl;
	while(q--)
	{
		int type,pos;
		cin>>type>>pos;
		if(type)
		{
			MS1.insert(pos);
			MS2.insert(-pos);
			multiset<int>::iterator it1,it2;
			it1=it2=MS1.lower_bound(pos);
			n++;
			if(n!=1)
			{
				if(it1==MS1.begin())
				{
					it2++;
					delta.insert(*it1-*it2);
				}
				else
				{
					it2++;
					if(it2==MS1.end())
					{
						it2--;
						it1--;
						delta.insert(*it1-*it2);
					}
					else
					{
						it1--;
						delta.erase(delta.lower_bound(*it1-*it2));
						it1++;
						delta.insert(*it1-*it2);
						it2--;
						it1--;
						delta.insert(*it1-*it2);
					}
				}
			}
		}
		else
		{
			multiset<int>::iterator it1,it2;
			it1=it2=MS1.lower_bound(pos);
			n--;
			if(n)
			{
				if(it1==MS1.begin())
				{
					it2++;
					delta.erase(delta.lower_bound(*it1-*it2));
				}
				else
				{
					it2++;
					if(it2==MS1.end())
					{
						it2--;
						it1--;
						delta.erase(delta.lower_bound(*it1-*it2));
					}
					else
					{
						it1--;
						delta.insert(*it1-*it2);
						it1++;
						delta.erase(delta.lower_bound(*it1-*it2));
						it2--;
						it1--;
						delta.erase(delta.lower_bound(*it1-*it2));
					}
				}
			}
			MS1.erase(MS1.lower_bound(pos));
			MS2.erase(MS2.lower_bound(-pos));
		}
		cout<<-(*MS1.begin()+*MS2.begin())+*delta.begin()<<endl;
	}
	return 0;
}