#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, string> pis;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<pis> curStanding(n);
	for (int i = 0; i < n; i++) {
		char name[21];
		scanf("%s%d", name, &curStanding[i].first);
		curStanding[i].first = -curStanding[i].first;
		curStanding[i].second = name;
	}
	sort(curStanding.begin(), curStanding.end());
	vector<int> points(n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &points[i]);
	}
	sort(points.begin(), points.end());
	int vasiaPos = -1;
	char vasiaName[21];
	scanf("%s", vasiaName);
	for (int i = 0; i < n; i++) {
		if (curStanding[i].second == vasiaName)
			vasiaPos = i;
	}
	int l = 0, r = n;
	pis vasiaSt(curStanding[vasiaPos].first - points.back(), vasiaName);
	while (r - l != 1) {
		int m = (l + r) / 2;
		bool possible = true;
		for (int i = n - 1, cnt = 0, j = n - m - 1; cnt < n - m; cnt++, i--, j--) {
			if (i == vasiaPos)
				--i;
			pis st(curStanding[i].first - points[j], curStanding[i].second);
			if (st < vasiaSt) {
				possible = false;
				break;
			}
		}
		if (possible) {
			r = m;
		} else
			l = m;
	}
	printf("%d ", r);
	l = 0, r = n;
	vasiaSt = pis(curStanding[vasiaPos].first - points.front(), vasiaName);
	while (r - l != 1) {
		int m = (l + r) / 2;
		bool possible = true;
		for (int i = 0, cnt = 0, j = n - m; cnt < m; cnt++, i++, j++) {
			if (i == vasiaPos)
				++i;
			pis st(curStanding[i].first - points[j], curStanding[i].second);
			if (st > vasiaSt) {
				possible = false;
				break;
			}
		}
		if (possible) {
			l = m;
		} else
			r = m;
	}
	printf("%d\n", l + 1);
	return 0;
}