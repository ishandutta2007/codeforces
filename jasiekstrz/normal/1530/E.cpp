#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void solve()
{
	string s;
	cin>>s;
	bool all_eq=true;
	for(size_t i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1])
		{
			all_eq=false;
			break;
		}
	}
	if(all_eq)
	{
		cout<<s<<"\n";
		return;
	}
	int cnt[30];
	for(int i='a';i<='z';i++)
		cnt[i-'a']=0;
	for(auto v:s)
		cnt[v-'a']++;
	char mn='a';
	for(char c='a';c<='z';c++)
	{
		if(cnt[c-'a']==1)
		{
			for(size_t i=0;i<s.size();i++)
			{
				if(s[i]==c)
				{
					swap(s[i],s[0]);
					break;
				}
			}
			sort(s.begin()+1,s.end());
			cout<<s<<"\n";
			return;
		}
		if(cnt[mn-'a']==0)
			mn=c;
	}
	int c=cnt[mn-'a'];
	vector<char> rst;
	for(auto v:s)
	{
		if(v!=mn)
			rst.push_back(v);
	}
	sort(rst.begin(),rst.end());
	reverse(rst.begin(),rst.end());
	if(c-2>rst.size())
	{
		if(rst[0]==rst.back())
		{
			cout<<mn;
			c--;
			for(auto v:rst)
				cout<<v;
			while(c--)
				cout<<mn;
			cout<<"\n";
			return;
		}
		else
		{
			char z;
			int it;
			for(it=rst.size()-1;rst[it]==rst.back();it--);
			z=rst[it];
			cout<<mn<<rst.back();
			c--;
			rst.pop_back();
			while(c--)
				cout<<mn;
			cout<<z;
			swap(rst[it],rst.back());
			rst.pop_back();
			while(!rst.empty())
			{
				cout<<rst.back();
				rst.pop_back();
			}
			cout<<"\n";
			return;
		}
	}
	else
	{
		cout<<mn<<mn;
		c-=2;
		while(c>0)
		{
			cout<<rst.back();
			cout<<mn;
			c--;
			rst.pop_back();
		}
		while(!rst.empty())
		{
			cout<<rst.back();
			rst.pop_back();
		}
		cout<<"\n";
		return;
	}
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