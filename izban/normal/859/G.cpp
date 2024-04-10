#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

string solve(string s) {
    int n = s.length();

    int x = n;
    vector<int> vct;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            vct.push_back(i);
            while (x % i == 0) x /= i;
        }
    }

    int prod = 1;
    for (int d : vct) prod *= d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] - '0') * prod;
    }

    while (1) {
        bool changed = 0;
        for (int d : vct) {
            int r = n / d;
            for (int i = 0; i < r; i++) {
                ll sum = 0;
                for (int j = 0; j < d; j++) sum += a[i + j * r];
                if (sum != 0) {
                    changed = 1;
                    assert(sum % d == 0);
                    for (int j = 0; j < d; j++) a[i + j * r] -= sum / d;
                }
            }
        }
        if (!changed) break;
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) ok &= a[i] == 0;
    string ans = ok ? "YES" : "NO";
    return ans;
}

char buf[N];

void test(int n, int k) {
    for (int i = 0; i < n; i++) {
        buf[i] = (char)('0' + rand() % k);
    }
    cout << solve(buf) << endl;
}

void stress() {
    for (int it = 0;; it++) {
        cerr << it << endl;
        srand(it);

        int n = rand() % 100 + 1;
        int k = rand() % 10 + 1;
        test(n, k);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //test();
    //stress();

    int n;
    while (scanf("%d", &n) == 1) {
        scanf("%s", buf);

        printf("%s\n", solve(buf).c_str());
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}