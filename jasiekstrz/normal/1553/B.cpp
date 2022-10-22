#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
bool ok(string s,string t)
{
	int m=t.size();
	for(int i=1;i<t.size();i++)
	{
		if(2*i-1<t.size())
			continue;
		bool g=true;
		for(int j=1;i-1+j<t.size();j++)
		{
			if(t[i-1-j]!=t[i-1+j])
			{
				g=false;
				break;
			}
		}
		if(g)
		{
			m=i;
			break;
		}
	}
	for(int i=0;i+m-1<s.size();i++)
	{
		bool g=true;
		for(int j=0;j<m;j++)
		{
			if(t[j]!=s[i+j])
			{
				g=false;
				break;
			}
		}
		if(g)
			return true;
	}
	return false;
}
void solve()
{
	string s,t;
	cin>>s>>t;
	if(ok(s,t))
		cout<<"YES\n";
	else
	{
		reverse(t.begin(),t.end());
		if(ok(s,t))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		solve();
	return 0;
}