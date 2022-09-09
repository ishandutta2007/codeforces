#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxk = 32;
const int maxn = 1000006;

vector<int> notused[maxk];
int a[maxn], b[maxn];
int n, m;

inline int which(int a)
{
    int ans = 0;
    while (a)
    {
	ans++;
	a >>= 1;
    }
    return ans - 1;
}

bool can(int m)
{
    for (int i = 0; i < maxk; i++) notused[i].resize(0);
    for (int i = 0; i < n; i++) notused[which(a[i])].push_back(a[i]);
    int cur = maxk - 1;
    for (int i = m - 1; i >= 0; i--)
    {
	while (cur >= 0 && notused[cur].size() == 0) cur--;
	if (cur < b[i]) return false;
	int cura = notused[cur].back();
	notused[cur].pop_back();
	assert(cura >= (1 << b[i]));
	cura -= (1 << b[i]);
	if (cura > 0) notused[which(cura)].push_back(cura);
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(b, b + m);
    int l = 0;
    int r = m + 1;
    while (r - l > 1)
    {
	int m = (l + r) / 2;
	if (can(m)) l = m;
	else r = m;
    }
    cout << l << endl;
    return 0;
}