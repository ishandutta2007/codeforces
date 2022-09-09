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
	bool was;
	int kv[20];
	tnode *link[30];
	tnode()
	{
		was = false;
		for (int i = 0; i < 20; i++) kv[i] = 0;
		for (int i = 0; i < 30; i++) link[i] = NULL;
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

void add(pnode cur, char *s, int curc, int len, int id)
{
// 	cout << "add " << cur << ' ' << curc << " of " << len << " of " << id << endl;
	cur->kv[id]++;
	if (curc == len) return;
	if (cur->link[s[curc] - 'a'] == NULL) cur->link[s[curc] - 'a'] = new tnode;
	add(cur->link[s[curc] - 'a'], s, curc + 1, len, id);
}

void check(pnode cur, char *s, int curc, int len)
{
	if (!cur->was)
	{
		cur->was = true;
		bool ok = true;
		for (int i = 0; i < n; i++) if (cur->kv[i] < l[i] || cur->kv[i] > r[i]) ok = false;
		if (ok) answer++;
	}
	if (curc == len) return;
	if (cur->link[s[curc] - 'a'] == NULL) cur->link[s[curc] - 'a'] = new tnode();
	check(cur->link[s[curc] - 'a'], s, curc + 1, len);
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
	answer = 0;
	for (int i = 0; i < n; i++)
	{
// 		cout << "add " << i << endl;
		for (int j = 0; j < len[i]; j++) add(root, p[i], j, len[i], i);
// 		cout << "added " << i << endl;
	}
	root->was = true;
	for (int i = 0; i < m; i++) check(root, s, i, m);
	cout << answer << endl;
	return 0;
}