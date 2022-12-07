#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n, sg[N], vis[N];
int s[N], sn;

int main() {
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		sn = 0;
		for (int k = 2; k * (k - 1) / 2 < i; k++) {
			int tmp = i - k * (k - 1) / 2;
			if (tmp % k) continue;
			int a1 = tmp / k;
			s[sn++] = (sg[a1 - 1]^sg[a1 + k - 1]);
			vis[sg[a1 - 1]^sg[a1 + k - 1]] = 1;
		}
		for (int k = 0; ; k++) if (!vis[k]) {
			sg[i] = k;
			break;
		}
		for (int k = 0; k < sn; k++) vis[s[k]] = 0;
		sg[i] ^= sg[i - 1];
	}
	if ((sg[n]^sg[n - 1]) == 0) printf("-1\n");
	else {
		for (int k = 2; k * (k - 1) / 2 < n; k++) {
			int tmp = n - k * (k - 1) / 2;
			if (tmp % k) continue;
			int a1 = tmp / k;
			if ((sg[a1 - 1]^sg[a1 + k - 1]) == 0) {
				printf("%d\n", k);
				break;
			}
		}
	}
	return 0;
}