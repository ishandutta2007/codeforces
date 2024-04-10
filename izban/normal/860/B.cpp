#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

char buf[N];

void solve(vector<string> a) {
    int m = a.size();

    unordered_map<ll, int> last;
    unordered_map<ll, int> cnt;
    for (int t = 0; t < m; t++) {
        string s = a[t];

        int n = s.length();
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur = 10 * cur + (s[j] - '0');

                ll o = (j - i + 1) + cur * 10LL;

                if (last.count(o) == 0 || last[o] != t) {
                    last[o] = t;
                    cnt[o]++;
                }
            }
        }
    }

    vector<string> ans(m, string(15, 'z'));
    for (int t = 0; t < m; t++) {
        string s = a[t];

        int n = s.length();
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur = 10 * cur + (s[j] - '0');

                ll o = (j - i + 1) + cur * 10LL;
                if (cnt[o] == 1) {
                    if (ans[t].length() > j - i + 1) {
                        ans[t] = s.substr(i, j - i + 1);
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) printf("%s\n", ans[i].c_str());
}

void test() {
    int n = 70000;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < 9; j++) {
            s += (char)('0' + rand() % 10);
        }
        a.push_back(s);
    }
    solve(a);
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //test();

    int m;
    while (scanf("%d", &m) == 1) {
        vector<string> a(m);
        for (int i = 0; i < m; i++) {
            scanf("%s", buf);
            a[i] = buf;
        }

        solve(a);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}