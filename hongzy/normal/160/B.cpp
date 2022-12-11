#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 410;
char s[N];
int n, cnt[2][10];

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i ++) {
		cnt[0][s[i] - '0'] ++;
	}
	for(int i = 1; i <= n; i ++) {
		cnt[1][s[i + n] - '0'] ++;
	}
	bool tag = 0;
	if(!cnt[0][0]) {
		bool ok = 1;
		int cnt1 = cnt[1][0];
		for(int i = 1; i < 10; i ++) {
			if(cnt[0][i] > cnt1) {
				ok = 0; break ;
			}
			cnt1 -= cnt[0][i];
			cnt1 += cnt[1][i];
		}
		if(cnt1 > 0) ok = 0;
		if(ok) tag = 1;
	}
	if(!tag && !cnt[0][9]) {
		bool ok = 1;
		int cnt1 = cnt[1][9];
		for(int i = 8; i >= 0; i --) {
			if(cnt[0][i] > cnt1) {
				ok = 0; break ;
			}
			cnt1 -= cnt[0][i];
			cnt1 += cnt[1][i];
		}
		if(cnt1 > 0) ok = 0;
		if(ok) tag = 1;
	}
	puts(tag ? "YES" : "NO");
	return 0;
}