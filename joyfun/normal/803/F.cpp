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
const int mod = 1e9+7;
int n, cnt[N], mi[N];

int main() {
	mi[0] = 1;
	for (int i = 1; i < N; i++) mi[i] = mi[i - 1] * 2 % mod;
	scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i < N; i++)
		for (int j = i + i; j < N; j += i) cnt[i] = (cnt[i] + cnt[j]) % mod;
	for (int i = 1; i < N; i++) cnt[i] = (mi[cnt[i]] - 1 + mod) % mod;
	for (int i = N; i >= 1; i--) 
		for (int j = i + i; j < N; j += i) cnt[i] = (cnt[i] - cnt[j] + mod) % mod;
	printf("%d\n", cnt[1]);
	return 0;
}