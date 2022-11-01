#include <bits/stdc++.h>
using namespace std;

vector<int> qus[500];

void ans(int at)
{
	printf("! %d\n", at);
	fflush(stdout);
}

vector<int> qu(int at)
{
	if (qus[at].empty())
	{
		printf("? %d\n", at);
		fflush(stdout);
		int k; scanf("%d", &k);
		while (k--)
		{
			int x; scanf("%d", &x);
			qus[at].push_back(x);
		}
	}
	return qus[at];
}


void slv()
{
	int h; scanf("%d", &h);
	for (int i = 1;i <= (1<<h);i++) qus[i].clear();
	int at = 1, dep = -1;
	vector<int> ch = qu(1);
	if (ch.size() == 2) { ans(1); return; }
	else if (ch.size() == 1) dep = h;
	else
	{
		vector<int> rt = move(ch);
		vector<int> o{1, rt[0]};
		while (true)
		{
			ch = qu(*o.rbegin());
			if (ch.size() == 2) { ans(*o.rbegin()); return; }
			else if (ch.size() == 1) break;
			else if (qus[ch[0]].empty()) o.push_back(ch[0]);
			else o.push_back(ch[1]);
		}
		reverse(o.begin(), o.end());
		o.push_back(rt[1]);
		while (true)
		{
			ch = qu(*o.rbegin());
			if (ch.size() == 2) { ans(*o.rbegin()); return; }
			else if (ch.size() == 1) break;
			else if (qus[ch[0]].empty()) o.push_back(ch[0]);
			else o.push_back(ch[1]);
		}
		at = o[o.size()/2];
		dep = h-o.size()/2;
	}
	while (dep > 4)
	{
		vector<int> o(h-dep); o.push_back(at);
		ch = qu(at);
		for (int u: ch) if (qus[u].empty()) o.push_back(u);
		while (true)
		{
			ch = qu(*o.rbegin());
			if (ch.size() == 2) { ans(*o.rbegin()); return; }
			else if (ch.size() == 1) break;
			else if (qus[ch[0]].empty()) o.push_back(ch[0]);
			else o.push_back(ch[1]);
		}
		at = o[o.size()/2];
		dep = h-o.size()/2;
	}
	vector<int> cand;
	ch = qu(at);
	for (int u: ch) if (qus[u].empty()) at = u;
	ch = qu(at);
	if (ch.size() == 2) { ans(at); return; }
	for (int u: ch) if (qus[u].empty())
	{
		vector<int> tmp = qu(u);
		if (tmp.size() == 2) { ans(u); return; }
		for (int v: tmp) if (v != at) cand.push_back(v);
	}
	while (cand.size() > 1)
	{
		int u = cand.back(); cand.pop_back();
		ch = qu(u);
		if (ch.size() == 2) { ans(u); return; }
	}
	ans(cand[0]);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) slv();
	return 0;
}