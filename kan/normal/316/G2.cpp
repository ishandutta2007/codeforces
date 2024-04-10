#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

struct tnode
{
	bool ok;
	int kv;
	vector<pair<int, tnode*> > link;
	tnode()
	{
		ok = true;
		kv = 0;
		link.resize(0);
	}
};

typedef tnode* pnode;

const int maxn = 50005;

char s[maxn];
char p[20][maxn];
int len[20];
int l[20], r[20];
int n, m;
int answer;

void add(pnode cur, char *s, int curc, int len)
{
// 	cout << "add " << cur << ' ' << curc << " of " << len << endl;
	if (curc == len) return;
	int to_find = s[curc] - 'a';
	int wh = -1;
	for (int i = 0; i < (int)cur->link.size(); i++) if (cur->link[i].first == to_find)
	{
		wh = i;
		break;
	}
	if (wh == -1)
	{
		wh = cur->link.size();
		cur->link.push_back(make_pair(to_find, new tnode));
	}
	add(cur->link[wh].second, s, curc + 1, len);
}

void check(pnode cur, char *s, int curc, int len)
{
	cur->kv++;
	if (curc == len) return;
	int to_find = s[curc] - 'a';
	int wh = -1;
	for (int i = 0; i < (int)cur->link.size(); i++) if (cur->link[i].first == to_find)
	{
		wh = i;
		break;
	}
	if (wh == -1) return;
	check(cur->link[wh].second, s, curc + 1, len);
}

void goall(pnode cur, int l, int r)
{
	if (cur->kv < l || cur->kv > r) cur->ok = false;
	cur->kv = 0;
	for (int i = 0; i < (int)cur->link.size(); i++) goall(cur->link[i].second, l, r);
}

void calc(pnode cur)
{
	if (cur->ok) answer++;
	for (int i = 0; i < (int)cur->link.size(); i++) calc(cur->link[i].second);
}

int main()
{
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d", p[i], &l[i], &r[i]);
		len[i] = strlen(p[i]);
	}
	int m = strlen(s);
	pnode root = new tnode;
	for (int i = 0; i < m; i++) add(root, s, i, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < len[i]; j++) check(root, p[i], j, len[i]);
		goall(root, l[i], r[i]);
	}
	answer = 0;
	root->ok = false;
	calc(root);
	cout << answer << endl;
	return 0;
}