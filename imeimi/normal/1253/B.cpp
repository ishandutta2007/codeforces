#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

void fail() {
    printf("-1\n");
    exit(0);
}

int n, cnt = 0;
bool in[1000001];
int last[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    vector<int> ans;
    int pr = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            if (!in[-x]) fail();
            last[-x] = i;
            in[-x] = 0;
            --cnt;
        }
        else {
            if (in[x]) fail();
            if (pr < last[x]) fail();
            in[x] = 1;
            ++cnt;
        }
        if (cnt == 0) {
            ans.push_back(i - pr);
            pr = i;
        }
    }
    if (cnt > 0) fail();
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    return 0;
}