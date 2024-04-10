#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll v[4005], d[4005], p[4005];
vector<int> ans;
int n;

int main()
{
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> v[i] >> d[i] >> p[i];
	for (int i = 0;i < n;i++) if (p[i] >= 0)
	{
		ans.push_back(i);
		ll b = v[i];
		queue<int> q;
		for (int j = i+1;j < n && b;j++) if (p[j] >= 0 && (p[j]-=(b--)) < 0)
			q.push(j);
		while (!q.empty())
		{
			int u(q.front()); q.pop();
			for (int j = u+1;j < n;j++) if (p[j] >= 0 && (p[j]-=d[u]) < 0)
				q.push(j);
		}
	}
	cout << ans.size() << endl;
	for (int u: ans) cout << u+1 << " ";
	cout << endl;
	return 0;
}