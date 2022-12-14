#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxNT = 100005;
const int MaxNL = 20;
const int MaxTN = MaxNT * MaxNL;

int nT;
char op[MaxNL];
char cmd[MaxNL];

int tn = 1;
int next[MaxTN][2];
int cnt[MaxTN];

inline void trie_insert(s64 w, int delta)
{
	int x = 1;
	for (int i = 0; i < 18; ++i, w /= 10)
	{
		int b = (w % 10) & 1;
		if (next[x][b] == 0)
			next[x][b] = ++tn;
		x = next[x][b];
	}
	cnt[x] += delta;
}
inline int trie_match()
{
	int x = 1;
	int l = strlen(cmd);
	for (int i = 0; i < l; ++i)
		x = next[x][cmd[l - i - 1] - '0'];
	for (int i = l; i < 18; ++i)
		x = next[x][0];
	return cnt[x];
}

int main()
{
	cin >> nT;
	while (nT--)
	{
		scanf("%s", op);
		if (op[0] == '?')
		{
			scanf("%s", cmd);
			printf("%d\n", trie_match());
		}
		else
		{
			s64 w;
			scanf("%I64d", &w);
			if (op[0] == '+')
				trie_insert(w, 1);
			else
				trie_insert(w, -1);
		}
	}

	return 0;
}