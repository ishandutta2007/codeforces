#include <bits/stdc++.h>
using namespace std;

set <string> s;
queue <string> q;
vector <string> G[6];

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string a,b;
	for (int i=0;i<m;i++)
	{
		cin >> a >> b;
		G[b[0]-'a'].push_back(a);
	}
	q.push((string)"a");
	while (!q.empty())
	{
		string u=q.front();q.pop();
		if (u.size()<n)
		{
			int c=u[0]-'a';
			string t1=u.substr(1,u.size()),t2;
			for (int i=0;i<G[c].size();i++)
			{
				string t2=G[c][i]+t1;
				if (s.find(t2)==s.end())
				{
					s.insert(t2);
					q.push(t2);
				}
			}
		}
	}
	int ans=0;
	for (set <string> :: iterator it=s.begin();it!=s.end();++it)
		if ((*it).size()==n)
			ans++;
	cout << ans;
	return 0;
}