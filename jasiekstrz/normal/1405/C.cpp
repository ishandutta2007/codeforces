#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int xd[2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,k,i;
	string s;
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		cin>>s;
		for(i=n-1;i>=k;i--)
		{
			if(s[i]=='?');
			else if(s[i-k]=='?')
				s[i-k]=s[i];
			else if(s[i]!=s[i-k])
			{
				cout<<"NO\n";
				goto fin;
			}
		}
		xd[0]=xd[1]=0;
		for(i=0;i<k;i++)
		{
			xd[0]+=(s[i]=='0');
			xd[1]+=(s[i]=='1');
		}
		if(k-xd[0]-xd[1]>=abs(xd[0]-xd[1]))
			cout<<"YES\n";
		else
			cout<<"NO\n";
		fin:;
	}
	return 0;
}