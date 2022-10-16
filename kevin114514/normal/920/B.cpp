#include<bits/stdc++.h>
using namespace std;
int ans[1010];
int L[1010],R[1010],pos;
void solve()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>L[i]>>R[i];
	vector<int> q;
	for(int i=1;i<=5000;i++)
	{
		//in
		while(pos<N&&L[pos]==i)
		{
			q.push_back(pos);
			pos++;
		}
		//out
		if(q.size())
		{
			int x=q.front();
			q.erase(q.begin());
			ans[x]=i;
		}
		for(int j=0;j<q.size();j++)
			if(R[q[j]]==i)
			{
				ans[q[j]]=0;
				q.erase(q.begin()+j);
				j--;
			}
	}
	for(int i=0;i<N;i++)
		cout<<ans[i]<<" ";
	puts("");
	pos=0;
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}