#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> nums;
map<int, int> comp;
const int mn = 3e+5;
int x1[mn], yy1[mn], x2[mn], y2[mn];
int psax[mn], psay[mn],decx[mn],decy[mn];
vector<int> valx, valy;
int n;
bool val(int x, int y) {
	int num = 0;
	for (int i = 0; i < n; i++)if (x >= x1[i] && x <= x2[i] && y >= yy1[i] && y <= y2[i])num++;
	if (num >= n - 1)return 1;
	return 0;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d%d%d%d", x1 + i, yy1 + i, x2 + i, y2 + i), nums.insert(x1[i]), nums.insert(x2[i]);
	i = 0;
	for (int x : nums) { decx[i] = x; comp[x] = i++; }
	for (i = 0; i < n; i++)x1[i] = comp[x1[i]], x2[i] = comp[x2[i]];
	nums.clear();
	comp.clear();
	for (i = 0; i < n; i++)nums.insert(yy1[i]), nums.insert(y2[i]);
	i = 0;
	for (int x : nums) {
		decy[i] = x; comp[x] = i++;
	}
	for (i = 0; i < n; i++)yy1[i] = comp[yy1[i]], y2[i] = comp[y2[i]];
	for (i = 0; i < n; i++)psax[x1[i]]++, psax[x2[i] + 1]--, psay[yy1[i]]++, psay[y2[i] + 1]--;
	for (i = 1; i < mn; i++) {
		psax[i] += psax[i - 1], psay[i] += psay[i - 1];
		if (psax[i] >= n - 1)valx.push_back(i);
		if (psay[i] >= n - 1)valy.push_back(i);
	}
	for (int x : valx) {
		for (int y : valy) { 
			if (val(x, y)) {
				printf("%d %d", decx[x], decy[y]);
				getchar(); getchar();
				return 0;
			} 
		}
	}
}