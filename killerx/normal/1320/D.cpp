#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define endl "\n"

const int mul[2] = {233, 19260817};
const int mod[2] = {998244353, 1000000007};

struct H {
#define R for (int k = 0; k < 2; ++ k)
	int h[2];
	H() {h[0] = h[1] = 0;}
	H(int x) {h[0] = h[1] = x;}
	H(int x, int y) {h[0] = x; h[1] = y;}
	H(const int a[2]) {h[0] = a[0]; h[1] = a[1];}
	H operator + (H rhs) {H ans; R ans.h[k] = (h[k] + rhs.h[k]) % mod[k]; return ans;}
	H operator - (H rhs) {H ans; R ans.h[k] = (h[k] + mod[k] - rhs.h[k]) % mod[k]; return ans;}
	H operator * (H rhs) {H ans; R ans.h[k] = 1LL * h[k] * rhs.h[k] % mod[k]; return ans;}
	bool operator == (H rhs) {R if (h[k] != rhs.h[k]) return 0; return 1;}
} M(mul);

ostream &operator << (ostream &out, H x) {return out << "(" << x.h[0] << " " << x.h[1] << ")";}

const int N = 2e5 + 5;

int n;
char s[N];
int sum[N];
H h[N], pw[N];
vector <int> cnt;
vector <int> zero;

H get(int l, int r) {return h[r] - h[l] * pw[r - l];}
int qry(int l, int r) {return sum[r] - sum[l];}

void precalc() {
	s[0] = '0';
	s[++ n] = '0'; n ++;
	for (int i = 0; i < n; ++ i)
		sum[i + 1] = sum[i] + s[i] - '0';
	int lst = 0;
	zero.push_back(0);
	for (int i = 1; i < n; ++ i) {
		if (s[i] == '0') {
			zero.push_back(i);
			cnt.push_back((i - 1 - lst) & 1);
			lst = i;
		}
	}
	pw[0] = 1;
	for (int i = 0; i < cnt.size(); ++ i) {
		pw[i + 1] = pw[i] * M;
		h[i + 1] = h[i] * M + H(cnt[i] + 10);
	}
}

H cal(int l, int r) {
	int il0 = lower_bound(zero.begin(), zero.end(), l) - zero.begin();
	int ir0 = lower_bound(zero.begin(), zero.end(), r) - zero.begin() - 1;
	if (il0 > ir0) return H((qry(l, r) & 1) + 10);
	int l0 = zero[il0], r0 = zero[ir0], ilen = ir0 - il0;
	H h = get(il0, ir0);
	h = h + pw[ilen] * H((qry(l, l0) & 1) + 10);
	h = h * M + H((qry(r0 + 1, r) & 1) + 10);
	return h;
}

void Main() {
	int l1, l2, len;
	cin >> l1 >> l2 >> len;
	int r1 = l1 + len;
	int r2 = l2 + len;
	if (cal(l1, r1) == cal(l2, r2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> (s + 1); precalc();
	int q; cin >> q;
	while (q --) Main();
	return 0;
}