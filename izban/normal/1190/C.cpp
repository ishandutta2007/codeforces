#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const string FIRST = "tokitsukaze";
const string DRAW = "once again";
const string SECOND = "quailty";

string solve(string s, int k) {
    int n = s.length();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';


    vector<vector<int>> pos(2);
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }

    for (int j = 0; j < 2; j++) {
        if (pos[j].empty() || pos[j].back() - pos[j].front() + 1 <= k) {
            return FIRST;
        }
    }

    assert(!pos[0].empty() && !pos[1].empty());

    bool can_draw = 0;
    for (int i = 0; i + k <= n; i++) {
        int L = i, R = i + k - 1;
        for (int c = 0; c < 2; c++) {
            int max_pos = -INF, min_pos = +INF;

            if (pos[c ^ 1].back() > R) max_pos = pos[c ^ 1].back();
            else {
                int j = lower_bound(pos[c ^ 1].begin(), pos[c ^ 1].end(), L) - pos[c ^ 1].begin();
                assert(j > 0);
                max_pos = pos[c ^ 1][j - 1];
            }

            if (pos[c ^ 1].front() < L) min_pos = pos[c ^ 1].front();
            else {
                int j = upper_bound(pos[c ^ 1].begin(), pos[c ^ 1].end(), R) - pos[c ^ 1].begin();
                assert(j < (int)pos[c ^ 1].size());
                min_pos = pos[c ^ 1][j];
            }

            assert(min_pos <= max_pos);
            if (max_pos - min_pos + 1 > k) {
                can_draw = 1;
            }
        }
    }
    if (can_draw) return DRAW;
    return SECOND;
}


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        static char buf[(int)1.01e6];
        scanf("%s", buf);
        string s = buf;
        cout << solve(s, k) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}