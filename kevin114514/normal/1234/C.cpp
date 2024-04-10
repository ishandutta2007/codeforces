#include<bits/stdc++.h>
using namespace std;
string S[2];
string dfs(int x,int y,bool z)
{
	if(y==S[0].length())
		return x?"YES":"NO";
	if(z)
	{
		if(S[x][y]<'3')
			return "NO";
		return dfs(x,y+1,0);
	}
	if(S[x][y]<'3')
		return dfs(x,y+1,0);
	return dfs(x^1,y,1);
}
void solve()
{
	int N;
	cin>>N;
	cin>>S[0]>>S[1];
	cout<<dfs(0,0,0)<<endl;
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
}