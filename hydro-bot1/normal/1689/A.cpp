#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		string s,t;
		cin>>s>>t;
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		reverse(s.begin(),s.end());
		reverse(t.begin(),t.end());
		string ans;
		int cnt=0;
		while(not s.empty() and not t.empty())
		{
			if(cnt==k)
			{
				cnt=-1;
				ans.push_back(t.back());
				t.pop_back();
			}
			else if(cnt==-k)
			{
				cnt=1;
				ans.push_back(s.back());
				s.pop_back();
			}
			else if(s.back()<t.back())
			{
				if(cnt<0)cnt=1;
				else cnt++;
				ans.push_back(s.back());
				s.pop_back();
			}
			else
			{
				if(cnt>0)cnt=-1;
				else cnt--;
				ans.push_back(t.back());
				t.pop_back();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}