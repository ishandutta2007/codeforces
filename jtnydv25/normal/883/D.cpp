#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int N = 1000005;

int n;
char s[N], s1[N];
vi pos;
int cnt[N];

inline bool check(int t, char *s) {
	int cur = 1, done = 0;
	while (cur <= n) {
		// get position of next not-eaten star
		while (cur <= n && (cur <= done || s[cur] != '*')) {
			if (s[cur] == 'P')
				done = max(done, cur + t);
			cur++;
		}
		if (cur <= n) {
			int nextP = -1, n2P = -1, cnt = 0;
			for (int i=cur+1; i <= min(cur+t, n); i++) {
				if (s[i] == 'P') {
					if (nextP == -1)
						nextP = i;
					else {
						n2P = i; break;
					}
				} else if (s[i] == '*' && nextP > 0) {
					cnt++;
				}
			}
			if (nextP == -1)
				return false;
			if (n2P > 0) {
				if (cnt) done = max(done, nextP + t);
				else done = max(done, n2P + t);
				cur = n2P + 1;
			} else {
				cur = nextP + 1;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	for (int i=1; i<=n; i++) {
		s1[i] = s[n+1 - i];
	}
	int lft=n, rgt=0;
	for (int i=1; s[i]; i++) {
		if (s[i] == 'P') {
			pos.push_back(i);
		}
		cnt[i] = cnt[i-1];
		if (s[i] == '*') {
			lft = min(lft, i);
			rgt = i, cnt[i]++;
		}
	}
	if (pos.size() == 1) {
		if (cnt[pos[0]] > cnt[n] - cnt[pos[0]])
			cout << cnt[pos[0]] << " " << pos[0]-lft << endl;
		else if (cnt[pos[0]] < cnt[n] - cnt[pos[0]])
			cout << cnt[n]-cnt[pos[0]] << " " << rgt-pos[0] << endl;
		else {
			cout << cnt[pos[0]] << " " << min(rgt-pos[0], pos[0]-lft) << endl;
		}
		return 0;
	}
	int l=1, r=n;
	while (l < r) {
		int mid = (l+r) >> 1;
		if (check(mid, s) || check(mid, s1))
			r = mid;
		else
			l = mid+1;
	}
	assert(l < n);
	cout << cnt[n] << " " << l << endl;

	return 0;
}