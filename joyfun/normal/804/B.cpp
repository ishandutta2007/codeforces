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

const int N = 1000005;
const int mod = 1e9+7;
int n;
char s[N];

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int cnt = 0;
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i] == 'b') pp(cnt, 1);
		else {
			pp(ans, cnt);
			pp(cnt, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}