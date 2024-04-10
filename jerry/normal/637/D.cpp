#include <bits/stdc++.h>
using namespace std;

vector<string> sol[200005];
set<int> can;
int ob[200005];
bool dp[200005];
int to[200005];
int n, m, s, d;

string run(int l)
{
	if (!l) return string();
	char buf[32];
	sprintf(buf, "RUN %d", l);
	return string(buf);
}

string jump(int l)
{
	char buf[32];
	sprintf(buf, "JUMP %d", l);
	return string(buf);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0;i < n;i++) scanf("%d", ob+i);
	ob[n] = -1;
	n++;
	sort(ob, ob+n);
	can.insert(n-1);
	sol[n-1].push_back(run(m-ob[n-1]-1));
	for (int i = n-2;i >= 0;i--)
	{
		if (ob[i+1] - ob[i] - 2 >= s)
		{
			int jmp = ob[i+1]-1 + d;
			while (!can.empty() && ob[*can.rbegin()] >= jmp)
				can.erase(--can.end());
			if (can.size())
			{
				dp[i] = true;
				sol[i].push_back(run(ob[i+1]-ob[i]-2));
				sol[i].push_back(jump(ob[*can.begin()]-ob[i+1]+2));
				to[i] = *can.begin();
				can.insert(i);
			}
		}
	}
	if (dp[0])
	{
		int at = 0;
		while (true)
		{
			for (string u: sol[at]) printf("%s\n", u.c_str());
			if (at == n-1) break;
			at = to[at];
		}
	} else
		printf("IMPOSSIBLE\n");
	return 0;
}