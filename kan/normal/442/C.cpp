#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define left left_dsf
#define right right_dsf

const int maxn = 500005;

int a[maxn];
int left[maxn], right[maxn];
priority_queue<pair<int, int>> q2, delq;
bool was[maxn];
queue<int> q;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[0] = 0;
	a[n + 1] = 0;
	for (int i = 1; i <= n; i++) if (a[i] <= a[i + 1] && a[i] <= a[i - 1])
	{
		q.push(i);
		was[i] = true;
	}
	for (int i = 1; i <= n; i++) left[i] = i - 1, right[i] = i + 1;
	ll answer = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int l = left[cur];
		int r = right[cur];
		answer += min(a[l], a[r]);
		right[l] = r;
		left[r] = l;
		if (l >= 1 && a[l] <= a[left[l]] && a[l] <= a[right[l]] && !was[l])
		{
			q.push(l);
			was[l] = true;
		}
		if (r <= n && a[r] <= a[left[r]] && a[r] <= a[right[r]] && !was[r])
		{
			q.push(r);
			was[r] = true;
		}
	}

	for (int i = 1; i <= n; i = right[i]) q2.push(make_pair(min(a[left[i]], a[right[i]]), i));
	while (!q2.empty())
	{
		int cur = q2.top().second;
		answer += q2.top().first;
		q2.pop();
		int l = left[cur];
		int r = right[cur];
		right[l] = r;
		left[r] = l;
		if (l >= 1)
		{
			delq.push(make_pair(min(a[left[l]], a[cur]), l));
			q2.push(make_pair(min(a[left[l]], a[r]), l));
		}
		if (r <= n)
		{
			delq.push(make_pair(min(a[cur], a[right[r]]), r));
			q2.push(make_pair(min(a[l], a[right[r]]), r));
		}
		while (!delq.empty() && !q2.empty() && delq.top() == q2.top())
		{
			q2.pop();
			delq.pop();
		}
	}	
	
	cout << answer << endl;
	return 0;
}