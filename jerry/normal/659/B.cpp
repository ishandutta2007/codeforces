#include <bits/stdc++.h>
using namespace std;

map<int, vector<string> > reg[10005];
int n, m;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string sur; int r, sco;
		cin >> sur >> r >> sco;
		r--;
		reg[r][sco].push_back(sur);
	}
	for (int i = 0;i < m;i++)
	{
		auto it = reg[i].rbegin();
		vector<string> sol = it->second;
		if (sol.size() < 2)
		{
			it++;
			for (auto u: it->second)
				sol.push_back(u);
		}
		if (sol.size() == 2) cout << sol[0] << " " << sol[1] << "\n";
		else cout << "?\n";
	}
	return 0;
}