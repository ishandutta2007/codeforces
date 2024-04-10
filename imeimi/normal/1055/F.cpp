#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
llong k;
vector<pll> child[1000005];
llong dep[1000005];
void dfs(int x) {
    for (pll i : child[x]) {
        dep[i.first] = dep[x] ^ i.second;
        dfs(i.first);
    }
}

struct query {
    int L1, R1, L2, R2;
    llong process(int b) const {
        llong m1, m2;
        for (m1 = L1; m1 <= R1 && ((dep[m1] >> b) & 1) == 0; ++m1);
        --m1;
        for (m2 = L2; m2 <= R2 && ((dep[m2] >> b) & 1) == 0; ++m2);
        --m2;
        return (m1 - L1 + 1) * (m2 - L2 + 1) + (R1 - m1) * (R2 - m2);
    }
    void divideS(vector<query> &Q, int b) const {
        int m1, m2;
        for (m1 = L1; m1 <= R1 && ((dep[m1] >> b) & 1) == 0; ++m1);
        --m1;
        for (m2 = L2; m2 <= R2 && ((dep[m2] >> b) & 1) == 0; ++m2);
        --m2;
        Q.push_back({ L1, m1, L2, m2 });
        Q.push_back({ m1 + 1, R1, m2 + 1, R2 });
    }
    void divideB(vector<query> &Q, int b) const {
        int m1, m2;
        for (m1 = L1; m1 <= R1 && ((dep[m1] >> b) & 1) == 0; ++m1);
        --m1;
        for (m2 = L2; m2 <= R2 && ((dep[m2] >> b) & 1) == 0; ++m2);
        --m2;
        Q.push_back({ L1, m1, m2 + 1, R2 });
        Q.push_back({ m1 + 1, R1, L2, m2 });
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        int p; llong w;
        cin >> p >> w;
        child[p].emplace_back(i, w);
    }
    dfs(1);
    sort(dep + 1, dep + n + 1);
    vector<query> Q;
    Q.push_back({ 1, n, 1, n });
    llong ans = 0;
    for (int i = 61; 0 <= i; --i) {
        llong cnt = 0;
        for (query q : Q) cnt += q.process(i);
        vector<query> nQ;
        if (k <= cnt) {
            for (query q : Q) q.divideS(nQ, i);
        }
        else {
            k -= cnt;
            ans |= 1ll << i;
            for (query q : Q) q.divideB(nQ, i);
        }
        Q.clear();
        for (query q : nQ) {
            if (q.L1 <= q.R1 && q.L2 <= q.R2) Q.push_back(q);
        }
    }
    printf("%lld\n", ans);
    return 0;
}