#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string q,a;
	cin>>q;
	for(int i=0;i<q.size();i++)
	{
		if (q[i]=='.')
		a.append("0");
		else if (q[i+1]=='.')
		{
			a.append("1");
			i++;
		}
		else
		{
			a.append("2");
			i++;
		}
		
	}
	cout<<a;
	return 0;
}