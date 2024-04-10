#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

bool good[maxn];
int a[maxn];
int prev[maxn], next[maxn];
int n;
queue<int> q;
vector<int> to_del;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) q.push(i);
	for (int i = 0; i < n; i++) good[i] = true;
	for (int i = 0; i < n; i++) prev[i] = i - 1, next[i] = i + 1;
	prev[0] = n;
	good[n] = false;
	int IT = 0;
	while (true)
	{
		if (q.empty()) break;
		IT++;
		to_del.resize(0);
		while (!q.empty())
		{
			int cur = q.front();
			good[next[cur]] = false;
			to_del.push_back(next[cur]);
			q.pop();
		}
// 		cout << "it = " << IT << endl;
		for (int i = 0; i < (int)to_del.size(); i++)
		{
// 			cout << "del " << to_del[i] << endl;
			int l = prev[to_del[i]];
			int r = next[to_del[i]];
			prev[r] = l;
			next[l] = r;
// 			cout << "new " << l << ' ' << r << endl;
			if (good[l] && good[r] && a[l] > a[r]) q.push(l);
		}
	}
	cout << IT << endl;
	return 0;
}