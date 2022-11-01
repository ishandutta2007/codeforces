#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > in;
pair<int, int> all[105];
int row[105];
int ar[105];
int n;

void dec(int x)
{
	ar[x]--;
	if (ar[x] == -1) ar[x] = 0;
}

void out()
{
	printf("%d\n", ar[0]);
	printf("%d\n", in.size());
	for (auto& u: in)
	{
		for (int i = 0;i < n;i++) row[i] = 0;
		for (int v: u) row[v] = 1;
		for (int i = 0;i < n;i++) printf("%d", row[i]);
		printf("\n");
	}
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", ar+i);
	if (n == 2)
	{
		while (ar[0] != ar[1])
		{
			in.push_back({0, 1});
			dec(0); dec(1);
		}
		out();
		return 0;
	}
	while (true)
	{
		// take the two worst ones and decrease
		for (int i = 0;i < n;i++) all[i] = {ar[i], i};
		sort(all, all+n, greater<pair<int, int> >());
		// only if we don't reduce the minimum by doing so
		if (all[1].first == all[n-1].first) break;
		in.push_back({all[0].second, all[1].second});
		dec(all[0].second);
		dec(all[1].second);
	}
	if (all[0].first != all[n-1].first)
	{ // so now, there is one element that is greater than everything else
		// first, do the things that we can for free
		int oth = all[n-1].first, wh = all[0].second;
		for (auto& u: in)
		{
			if (ar[wh] == oth) break; // we are done
			if (u[0] == wh || u[1] == wh) continue; // nothing for free here
			u.push_back(wh); dec(wh);
		}
		if (ar[wh] == oth)
		{
			out();
			return 0;
		}
		queue<int> can;
		for (int i = 0;i < n;i++) if (i != wh) can.push(i);
		while (ar[wh] != oth)
		{
			in.push_back({wh, can.front()});
			dec(wh); dec(can.front());
			oth = min(oth, ar[can.front()]);
			can.push(can.front());
			can.pop();
		}
		vector<int> rem;
		for (int i = 0;i < n;i++) if (ar[i] != oth) rem.push_back(i);
		while (rem.size() >= 4 || rem.size() == 2)
		{
			in.push_back({*rem.rbegin(), *++rem.rbegin()});
			rem.pop_back();
			rem.pop_back();
		}
		if (rem.size() == 3)
			in.push_back({rem[0], rem[1], rem[2]});
		if (rem.size() == 1)
			in.back().push_back(rem[0]);
	}
	out();
	return 0;
}