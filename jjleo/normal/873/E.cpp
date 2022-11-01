#include <bits/stdc++.h>
#define maxn 3005
using namespace std;

int n;
pair<int, int> a[maxn];
int st[maxn][20], id[maxn][20], lg[maxn], pw[20];
int x, y, z;
int ans[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + 1 + n);
	for(int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	pw[0] = 1;for(int i = 1;i <= 10;i++) pw[i] = pw[i - 1] << 1;
	for(int i = 1;i <= n;i++) st[i][0] = a[i].first - a[i - 1].first, id[i][0] = i;
	for(int j = 1;j <= 10;j++){
		for(int i = 1;i + pw[j] - 1 <= n;i++){
			st[i][j] = max(st[i][j - 1], st[i + pw[j - 1]][j - 1]);
			id[i][j] = st[i][j] == st[i][j - 1] ? id[i][j - 1] : id[i + pw[j - 1]][j - 1];
		}
	}
	for(int i = 3;i <= n;i++){
		for(int j = 2;j < i;j++){
			if(!(i - j <= 2 * (n - i + 1) && n - i + 1 <= 2 * (i - j))) continue;
			if(x && a[i].first - a[i - 1].first < a[x].first - a[x - 1].first) continue;
			if(x && a[i].first - a[i - 1].first == a[x].first - a[x - 1].first && a[j].first - a[j - 1].first < a[y].first - a[y - 1].first) continue;
			if(j - (max(i - j, n - i + 1) + 1) / 2 < j - min(i - j, n - i + 1) * 2) continue;
			if(j - (max(i - j, n - i + 1) + 1) / 2 < 1) continue;
			int r = j - (max(i - j, n - i + 1) + 1) / 2;
			int l = max(j - min(i - j, n - i + 1) * 2, 1);
			//if(i == 222 && j == 141) printf("%d %d", l, r);
			int k = max(st[l][lg[r - l + 1]], st[r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]]);
			if(x && a[j].first - a[j - 1].first == a[y].first - a[y - 1].first && k < a[z].first - a[z - 1].first) continue;
			x = i, y = j, z = k == st[l][lg[r - l + 1]] ? id[l][lg[r - l + 1]] : id[r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]];
		}
	}
	for(int i = 1;i <= n;i++){
		if(i < z) ans[a[i].second] = -1;
		else if(i < y) ans[a[i].second] = 3;
		else if(i < x) ans[a[i].second] = 2;
		else ans[a[i].second] = 1;
	}
	//printf("%d %d %d--\n", x, y, z);
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}