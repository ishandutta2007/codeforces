#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 100005;

int n, num[N];
set<int> ans;
void init() {
	ans.clear();
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	sort(num, num + n);
}

bool solve() {
	if (n == 1) {
		return false;
	}
	if (n == 2) {
		int d = num[1] - num[0];
		ans.insert(num[0] - d);
		ans.insert(num[1] + d);
		if (d % 2 == 0)
			ans.insert(num[0] + d / 2);
		return true;
	}
	else {
		int d, dd, nn = 0; d = num[1] - num[0];
		map<int, int> vv; vv.clear();
		int save[N], saven = 0; save[saven++] = d;
		for (int i = 1; i < n; i++) {
			if (d != num[i] - num[i - 1]) {
				d = num[i] - num[i - 1];
				save[saven++] = d;
				nn++;
			}
			d = num[i] - num[i - 1];
			vv[d]++;
		}
		if (nn > 2) {
			return true;
		}
		else {
			if (nn == 0) {
				int d = num[1] - num[0];
				ans.insert(num[0] - d);
				ans.insert(num[n - 1] + d);
			}
			else {
				sort(save, save + saven);
				for (int k = saven - 1; k >= 0; k--) {
					if (vv[save[k]] == 1) {
						for (int ii = 1; ii < n; ii ++) {
							int dd = num[ii] - num[ii - 1];
							if (dd == save[k]) {
								if (dd % 2) return true;
								int ddd = dd / 2;
								for (int l = 0; l < saven; l++) {
									if (l == k) continue;
									if (save[l] != ddd) return true;
								}
								ans.insert(num[ii] - dd / 2);
								return true;	
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	init();
	if(!solve()) printf("-1\n");
	else {
		printf("%d\n", ans.size()); int bo = 0;
		for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
			if (bo++) printf(" ");
			printf("%d", *it);
		}
		if (ans.size() != 0)
			printf("\n");
	}
	return 0;
}