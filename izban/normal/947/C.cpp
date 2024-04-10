#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dbl;

const int INF = (int)1.01e9;
const int N = 1 << 19;
const int K = 30;

int sz;
int nxt[N * K][2];
int cnt[N * K];

void init() {
    sz = 1;
    memset(nxt, -1, sizeof(nxt));
}

void add(int x) {
    int cur = 0;
    cnt[cur]++;

    for (int i = 29; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (nxt[cur][c] == -1) {
            nxt[cur][c] = sz++;
        }
        cur = nxt[cur][c];
        cnt[cur]++;
    }
}

int find(int x) {
    int cur = 0;
    cnt[cur]--;

    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int c = (x >> i) & 1;
        bool found = 0;
        for (int cans = 0; cans < 2; cans++) {
            int symb = cans ^ c;
            if (nxt[cur][symb] != -1 && cnt[nxt[cur][symb]] > 0) {
                ans |= cans << i;
                found = 1;
                cur = nxt[cur][symb];
                cnt[cur]--;
                break;
            }
        }
        assert(found);
    }
    return ans;
}


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //cerr << sizeof(nxt) + sizeof(cnt) << endl;

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        init();
        for (int i = 0; i < n; i++) {
            add(b[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(find(a[i]));
        }
        for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }

    return 0;
}