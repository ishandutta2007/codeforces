#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 2e5 + 10, base = 1e5 + 3, P1 = 1e9 + 7, P2 = 1e9 + 9, inv_b1 = 540539193, inv_b2 = 63828724;
int n, m, sum[26][maxn], pow1[maxn], pow2[maxn]; char str[maxn]; pair <pii, int> s1[26], s2[26];
struct hashmap {
	vector <int> vec, sum1, sum2;
	void init(char c) {
		vec.push_back(0), sum1.push_back(0), sum2.push_back(0);
		for (int i = 1; i <= n; i++) {
			if (str[i] == c) {
				vec.push_back(i);
				sum1.push_back((1ll * base * sum1.back() + i) % P1);
				sum2.push_back((1ll * base * sum2.back() + i) % P2);
			}
		}
	}
	pii get(int l, int r) {
		int pl = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
		int pr = upper_bound(vec.begin(), vec.end(), r) - vec.begin() - 1;
		return pr < pl ? pii(-1, -1) :
    	pii(((sum1[pr] - 1ll * sum1[pl - 1] * pow1[pr - pl + 1] % P1 + P1) % P1 - 1ll * l * (pow1[pr - pl + 1] + P1 - 1) % P1 * inv_b1 % P1 + P1) % P1,
            ((sum2[pr] - 1ll * sum2[pl - 1] * pow2[pr - pl + 1] % P2 + P2) % P2 - 1ll * l * (pow2[pr - pl + 1] + P2 - 1) % P2 * inv_b2 % P2 + P2) % P2);
	}
} h[26];

int main() {
	int p1, p2, k; pow1[0] = pow2[0] = 1;
	scanf("%d %d %s", &n, &m, str + 1);
	for (int i = 0; i < 26; i++) {
		h[i].init('a' + i);
	}
	for (int i = 1; i <= n; i++) {
		pow1[i] = 1ll * base * pow1[i - 1] % P1;
		pow2[i] = 1ll * base * pow2[i - 1] % P2;
		for (int j = 0; j < 26; j++) {
			sum[j][i] = sum[j][i - 1];
		}
		sum[str[i] - 'a'][i]++;
	}
	while (m--) {
		scanf("%d %d %d", &p1, &p2, &k);
		for (int i = 0; i < 26; i++) {
			s1[i] = make_pair(h[i].get(p1, p1 + k - 1), sum[i][p1 + k - 1] - sum[i][p1 - 1]);
			s2[i] = make_pair(h[i].get(p2, p2 + k - 1), sum[i][p2 + k - 1] - sum[i][p2 - 1]);
		}
		bool flg = 1;
		sort(s1, s1 + 26), sort(s2, s2 + 26);
		for (int i = 0; i < 26 && flg; i++) {
			flg &= s1[i] == s2[i];
		}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}