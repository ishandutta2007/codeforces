#include<bits/stdc++.h>
using namespace std;
bool bylo[200010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,wyn,i;
	cin>>n;
	wyn=0;
	bylo[100000]=true;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		a+=100000;
		if(!bylo[a])
		{
			bylo[a]=true;
			wyn++;
		}
	}
	cout<<wyn;
	return 0;
}