#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
set<int> ans;
int f(string &s,int msk)
{
	int g[2]={0,0};
	int poss[2]={5,5};
	for(int i=0;i<10;i++)
	{
		if(s[i]=='1')
			g[i%2]++;
		else if(s[i]=='0')
			poss[i%2]--;
		else if(msk&(1<<i))
			g[i%2]++;
		else
			poss[i%2]--;
		if(g[0]>poss[1] || g[1]>poss[0])
			return i+1;
	}
	return 10;
}
void solve()
{
	ans.clear();
	ans.insert(10);
	string s;
	cin>>s;
	for(int msk=0;msk<(1<<10);msk++)
	{
		ans.insert(f(s,msk));
	}
	cout<<*ans.begin()<<"\n";
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