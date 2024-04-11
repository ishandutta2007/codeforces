#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;
int mod;

vector<int> numbers[maxn];
vector<int> children[maxn];
char forbid[maxn];

int dp[maxn];
int parent[maxn];

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

int power(int x, int p) {
    if (p == 0) return 1 % mod;
    if (p & 1) return x * power(x, p - 1) % mod;
    return power(x * x % mod, p >> 1);
}

int gcd (int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int step(int prev, int cur) {
    /*int g1 = gcd(prev, mod);
    int g2 = gcd(cur, mod);
    for (auto i: numbers[g2 / g1]) {
        if ((prev * i - cur) % mod == 0) {
            return i;
        }
    }*/
    int x, y;
    int g = gcd(prev, mod, x, y);
    return (x * (cur / g) % mod + mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int num;
    cin >> num >> mod;
    for (int i = 0; i < num; ++i) {
        int x;
        cin >> x;
        if (x == 0) x += mod;
        forbid[x] = true;
    }

    for (int i = 1; i <= mod; ++i) {
        if (!forbid[i]) {
            numbers[gcd(i, mod)].push_back(i % mod);
        }
    }
    for (int i = 1; i <= mod; ++i) {
        if (mod % i != 0) continue;
        for (int j = i + i; j <= mod; j += i) {
            if (mod % j != 0) continue;
            children[i].push_back(j);
        }
    }

    for (int i = mod; i >= 1; --i) {
        if (gcd(i, mod) != i) continue;
        int maxval = 0;
        parent[i] = -1;
        for (auto d: children[i]) {
            if (dp[d] > maxval) {
                maxval = dp[d];
                parent[i] = d;
            }
        }
        dp[i] = maxval + (int) numbers[i].size();
    }

    int current = 1;
    vector<int> muls;
    while (current != -1) {
        for (auto i: numbers[current]) {
            muls.push_back(i);
        }
        current = parent[current];
    }

    for (int i = 1; i <= mod; ++i) {
        if (forbid[i]) {
            numbers[gcd(i, mod)].push_back(i % mod);
        }
    }

    cout << muls.size() << '\n';
    for (int i = 0; i < muls.size(); ++i) {
        if (i == 0) {
            cout << muls[i] << ' ';
        } else {
            int tmp = step(muls[i - 1], muls[i]);
            //assert(tmp * muls[i - 1] % mod == muls[i] % mod);
            cout << tmp << ' ';
        }
    }
}