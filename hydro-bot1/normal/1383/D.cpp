// Hydro submission #617d356763b6465eb4e604b6@1635595623983
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

#define fk cerr << "fuck ccf\n"

const int N = 300;
int n, m;
struct info {
    int val;
    bool w[2];
    inline bool operator<(const info &Other) const {
        return this->val < Other.val;
    }
    inline bool operator>(const info &Other) const {
        return this->val > Other.val;
    }
    inline bool any() { return w[0] || w[1]; }
} a[N][N];
int ans[N][N];
std::vector<info> seq;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j].val;

    for (int i = 1; i <= n; ++i) {
        int max = 0, maxid = 0;
        for (int j = 1; j <= m; ++j)
            if (a[i][j].val > max) maxid = j, max = a[i][j].val;
        a[i][maxid].w[1] = true;
    }

    for (int j = 1; j <= m; ++j) {
        int max = 0, maxid = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i][j].val > max) maxid = i, max = a[i][j].val;
        a[maxid][j].w[0] = true;
    }

    seq.resize((n + 1) * (m + 1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            seq[(i - 1) * m + j] = a[i][j];

#ifdef DEBUG
    for (int i = 1; i <= n * m; ++i)
        cerr << '(' << seq[i].val << ' ' << seq[i].w[0] << ' ' << seq[i].w[1] << ')';
    cerr << '\n';
#endif

    std::sort(seq.begin() + 1, seq.end(), std::greater<info>());

    int cx = 0, cy = 0;
    static std::queue<std::pair<int, int>> rec;
    for (int i = 1; i <= n * m; ++i) {
        if (seq[i].any()) {
            if (seq[i].w[0]) ++cy;
            if (seq[i].w[1]) ++cx;
            if (seq[i].w[0]) for (int j = cx - 1; j; --j) rec.emplace(j, cy);
            if (seq[i].w[1]) for (int j = cy - 1; j; --j) rec.emplace(cx, j);
            ans[cx][cy] = seq[i].val;
            continue;
        }
        // assert(!rec.empty());
        ans[rec.front().first][rec.front().second] = seq[i].val;
        rec.pop();
    }
    fk;

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; ++j)
            cout << ans[i][j] << ' ';

    return 0;
}