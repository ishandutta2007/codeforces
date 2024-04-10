#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
bool solve()
{
	string s,t;
	cin>>s>>t;
	if(t.size()>s.size())
		return false;
	int par=(s.size()-t.size())%2;
	int i=0,j=0;
	while(true)
	{
		if(j>=t.size())
			return true;
		if(i>=s.size())
			return false;
		if(s[i]!=t[j] || i%2!=par)
		{
			i++;
			continue;
		}
		i++;
		j++;
		par=(par+1)%2;
		continue;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		cout<<(solve() ? "YES":"NO")<<"\n";
	return 0;
}