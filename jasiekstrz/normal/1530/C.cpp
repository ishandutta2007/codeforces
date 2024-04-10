#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void f(priority_queue<int> &p,int &s,int n)
{
	while(p.size()>n-(n/4))
	{
		s+=p.top();
		p.pop();
	}
	return;
}
void solve()
{
	int n;
	cin>>n;
	int s1=0,s2=0;
	priority_queue<int> p1,p2;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s1+=x;
		p1.push(-x);
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s2+=x;
		p2.push(-x);
	}
	f(p1,s1,n);
	vector<int> tmp;	
	while(p2.size()>n-(n/4))
	{
		s2+=p2.top();
		tmp.push_back(-p2.top());
		p2.pop();
	}
	sort(tmp.begin(),tmp.end());
	int ans=0;
	for(;s1<s2;ans++)
	{
		s1+=100;
		p1.push(-100);
		f(p1,s1,n+ans+1);
		while(!tmp.empty() && p2.size()+1<=n+ans+1-((n+ans+1)/4))
		{
			p2.push(-tmp.back());
			s2+=tmp.back();
			tmp.pop_back();
		}
		//cerr<<s1<<" "<<s2<<"\n";
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		solve();
	return 0;
}