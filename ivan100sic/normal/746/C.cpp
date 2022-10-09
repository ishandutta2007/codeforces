#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int s, x1, x2, t1, t2, p, d;

int dp[1005];
bool done[1005];

void suggest(int pos, int val) {
	if (val < dp[pos]) {
		dp[pos] = val;
	}
}

int main() {
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

	int tzp = (d == 1) ? p : (2*s-p);

	memset(dp, 63, sizeof(dp));
	dp[x1] = 0;
	
	// pretpostavimo integer
	while(1) {
		int x = 1004;
		for (int i=0; i<=s; i++) {
			if (!done[i] && dp[i] < dp[x]) {
				x = i;
			}
		}

		done[x] = true;
		// pomeri se peske
		if (x > 0) {
			suggest(x-1, dp[x] + t2);
		}
		if (x < s) {
			suggest(x+1, dp[x] + t2);
		}
		// sacekaj da tramvaj dodje i uhvati ga kad ide levo
		{
			int tgt = (2*s-x-tzp)*t1;
			int diff = tgt - dp[x];
			diff %= 2*s*t1;
			diff += 2*s*t1;
			diff %= 2*s*t1;
			suggest(x-1, dp[x] + diff + t1);
		}

		{
			int tgt = (x-tzp)*t1;
			int diff = tgt - dp[x];
			diff %= 2*s*t1;
			diff += 2*s*t1;
			diff %= 2*s*t1;
			suggest(x+1, dp[x] + diff + t1);
		}

		if (done[x2]) {
			cout << dp[x2];
			return 0;
		}
	}
}