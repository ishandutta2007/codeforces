#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5;
int t[N+10];
int solve()
{
	int n;
	cin>>n;
	string s[2];
	cin>>s[0]>>s[1];
	for(int i=0;i<n;i++)
	{
		if(s[0][i]=='0' && s[1][i]=='0')
			t[i+1]=0;
		else if(s[0][i]=='1' && s[1][i]=='1')
			t[i+1]=1;
		else
			t[i+1]=2;
	}
	t[0]=t[n+1]=2;
	int ans=0;
	bool ok=false;
	for(int i=1;i<=n;i++)
	{
		if(t[i]==2)
		{
			ans+=2;
			ok=false;
		}
		else if(t[i]==1)
			ok=true;
		else if(ok)
		{
			ans+=2;
			ok=false;
		}
		else if(t[i+1]==1)
		{
			ans+=2;
			ok=false;
			i++;
		}
		else
		{
			ans++;
			ok=false;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		cout<<solve()<<"\n";
	return 0;
}