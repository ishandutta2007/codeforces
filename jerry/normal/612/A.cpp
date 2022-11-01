#include <bits/stdc++.h>
using namespace std;

vector<string> sol;
string str;
int n, p, q;
bool vis[102];

bool slv(int at)
{
	if (at == 0) return true;
	if (at < 0) return false;
	if (vis[at]) return false;
	vis[at] = true;
	if (slv(at-p))
	{
		sol.push_back(str.substr(at-p, p));
		return true;
	}
	if (slv(at-q))
	{
		sol.push_back(str.substr(at-q, q));
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> p >> q >> str;
	if (!slv(n)) printf("-1\n");
	else
	{
		printf("%d\n", sol.size());
		for (auto u: sol) printf("%s\n", u.c_str());
	}
	return 0;
}