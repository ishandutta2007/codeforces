#include <bits/stdc++.h>
using namespace std;

struct item {
	int t, d, p, id;

	bool operator< (const item& other) const {
		return d + t < other.d + other.t;
	}
};

int n;
item a[105];

int dp[105][2005];
bool uzimam[105][2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i].t >> a[i].d >> a[i].p;
		a[i].d -= a[i].t;
		a[i].id = i;
	}

	sort(a+1, a+n+1);

	memset(dp, 128, sizeof(dp));
	dp[0][0] = 0;

	for (int i=1; i<=n; i++) {
		for (int vreme=0; vreme<a[i].d; vreme++) {
			if (dp[i][vreme+a[i].t] < dp[i-1][vreme] + a[i].p) {
				dp[i][vreme+a[i].t] = dp[i-1][vreme] + a[i].p;
				uzimam[i][vreme+a[i].t] = true;
			}
		}
		for (int vreme=0; vreme<=2001; vreme++) {
			if (dp[i][vreme] < dp[i-1][vreme]) {
				dp[i][vreme] = dp[i-1][vreme];
				uzimam[i][vreme] = false;
			}
		}
	}

	int solvreme = 0;
	vector<int> uzeti_id;
	int ukvred = 0;

	for (int vreme=0; vreme<=2001; vreme++) {
		if (ukvred < dp[n][vreme]) {
			ukvred = dp[n][vreme];
			solvreme = vreme;
		}
	}

	int x = n;
	while (x > 0) {
		if (uzimam[x][solvreme]) {
			solvreme -= a[x].t;
			uzeti_id.push_back(a[x].id);
		}
		x--;
	}

	reverse(uzeti_id.begin(), uzeti_id.end());

	cout << ukvred << '\n' << uzeti_id.size() << '\n';
	for (int x : uzeti_id) {
		cout << x << ' ';
	}

}