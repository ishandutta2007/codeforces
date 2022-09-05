#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
vector<int> ans;

void work(int l, int r) {
	if (a[l]) {
		assert(a[r] == 0);
		int t = ans.size();
		reverse(a + l, a + r + 1);
		work(l, r);
		for (int i = t; i < ans.size(); ++i) {
			int p = ans[i] - l + 1;
			p = p + 2;
			p = r - p + 1;
			ans[i] = l + p - 1;
		}
		return;
	}
	while (l < r) {
		if (a[l + 1] == 0) {
			++l;
			continue;
		}
		assert(l + 1 != r);
		if (a[l + 2]) {
			ans.push_back(l);
			a[l + 1] = a[l + 2] = 0;
			continue;
		}
		assert(l + 2 != r);
		if (a[l + 3]) {
			ans.push_back(l + 1);
			a[l + 1] = a[l + 3] = 0;
			continue;
		}
		ans.push_back(l + 1);
		a[l + 2] = a[l + 3] = 1;
	}
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			sum ^= a[i];
		}
		if (sum % 2) {
			puts("NO");
			continue;
		}
		ans.clear();
		if (a[1] == 0 || a[n] == 0) {
			work(1, n);
		} else {
			int p_sum = 0, i = 1;
			for (i = 1; i <= n; ++i)
				if (a[i])
					p_sum ^= 1;
				else if (p_sum == 0) {
					work(1, i);
					work(i, n);
					break;
				}
			if (i > n) {
				for (i = 1; i <= n; ++i)
					if (a[i] == 0) {
						int j = i;
						while (j <= n && a[j] == 0) ++j;
						--j;
						if ((j - i + 1) % 2) {
							while (j > i) {
								ans.push_back(j - 1);
								a[j - 1] = a[j] = 1;
								j -= 2;
							}
							ans.push_back(i - 1);
							a[i - 1] = a[i + 1] = 0;
							work(1, i);
							work(i, n);
							break;
						}
						i = j + 1;
					}
				if (i > n) {
					puts("NO");
					continue;
				}
			}
		}
		puts("YES");
		cout << ans.size() << endl;
		for (auto x: ans) printf("%d ", x);
		puts("");
	}
}