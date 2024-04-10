#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int tab[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>tab[i];
		vector<int> ans;
		for(i=1;i<=n;i+=2)
		{
			if((tab[i]+tab[i+1])%2==0)
			{
				ans.push_back(tab[i]);
				ans.push_back(tab[i+1]);
			}
			else
				ans.push_back(0);
		}
		cout<<ans.size()<<"\n";
		for(auto v:ans)
			cout<<v<<" ";
		cout<<"\n";
	}
	return 0;
}