#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100005;

int n, save[N];
vector<int> g[N];

int cal(int x) {
    int ans = 0, have = g[0].size(), sn = 0;
    for (int i = 1; i <= 100000; i++) {
	int j = 0;
	if (x <= g[i].size()) {
	    for (; j < g[i].size() - x + 1; j++) {
		ans += g[i][j];
		have++;
	    }
	}
	for (; j < g[i].size(); j++)
	    save[sn++] = g[i][j];
    }
    sort(save, save + sn);
    for (int i = 0; i < x - have; i++)
	ans += save[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; i++) {
	scanf("%d%d", &a, &b);
	g[a].push_back(b);
    }
    for (int i = 1; i <= 100000; i++)
	sort(g[i].begin(), g[i].end());
    int l = 1, r = n;
    while (l < r - 2) {
	int midl = (l * 2 + r) / 3;
	int midr = (l + r * 2) / 3;
	if (cal(midl) > cal(midr)) l = midl;
	else r = midr;
    }
    int ans = INF;
    for (int i = l; i <= r; i++)
	ans = min(ans, cal(i));
    printf("%d\n", ans);
    return 0;
}