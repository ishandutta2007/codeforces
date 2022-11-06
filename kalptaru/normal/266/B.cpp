#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string q;
	int n,t;
	cin>>n>>t;
	cin>>q;
	for(int i=0;i<t;i++)
	{
		for (int j=0;j<n-1;j++)
		{
			if(q[j]=='B' && q[j+1]=='G')
			{
				q[j]='G';
				q[j+1]='B';
				j++;
			}
		}
	}
	cout<<q;
	return 0;
}