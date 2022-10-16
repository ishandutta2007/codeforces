#include<bits/stdc++.h>
using namespace std;
int BIT[300001][26];
int X;
vector<int> Sum(int x)
{
	vector<int> ans(26,0);
	if(!x)
		return ans;
	string S;
	int y=x;
	while(y)
	{
		S+=(char)(y%2+'0');
		y/=2;
	}
	reverse(S.begin(),S.end());
	int Y=X;
	while(S.length())
	{
		if(S[0]=='1')
		{
			const int BITI=Y/(1<<(S.length()-1));
			for(int i=0;i<26;i++)
				ans[i]+=BIT[BITI][i];
			Y+=(1<<(S.length()-1));
		}
		S.erase(S.begin());
	}
	return ans;
}
int RSum(int a,int b)
{
	vector<int> A=Sum(a-1),B=Sum(b);
	int ans=0;
	for(int i=0;i<26;i++)
		if(B[i]>A[i])
			ans++;
	return ans;
}
int main()
{
	string S;
	cin>>S;
	int i;
	for(i=0;(1<<i)<S.length();i++);
	X=(1<<i);
	for(int i=X;i<X+S.length();i++)
	{
		int x=i;
		while(x)
		{
			BIT[x][S[i-X]-'a']++;
			x/=2;
		}
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			char c;
			cin>>x>>c;
			c-='a';
			x--;
			int fc=S[x]-'a';
			S[x]=c+'a';
			x+=X;
			while(x)
			{
				BIT[x][c]++;
				BIT[x][fc]--;
				x/=2;
			}
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<RSum(x,y)<<endl;
		}
	}
	return 0;
}