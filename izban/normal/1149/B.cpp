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

const int N = 253;
int dp[N][N][N];

void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, q;
    bool first = 1;
    while (scanf("%d%d", &n, &q) == 2) {
        if (first) first = 0;
        else cout << endl;

        static char buf[(int) 1.01e6];
        scanf("%s", buf);
        string s = buf;

        vector<vector<int>> nxt(n + 2, vector<int>(26, n));
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }

        vector<int> len(3);
        vector<vector<int>> cur(3);

        dp[0][0][0] = 0;
        while (q--) {
            char t;
            int id;
            scanf(" %c%d", &t, &id);
            id--;


            if (t == '+') {
                char c;
                scanf(" %c", &c);
                int cc = c - 'a';

                len[id]++;
                cur[id].push_back(cc);

                vector<int> i(3);
                vector<int> mn(3), mx(3);
                for (int j = 0; j < 3; j++) {
                    mn[j] = 0;
                    mx[j] = len[j];
                }
                mn[id] = len[id];

                for (i[0] = mn[0]; i[0] <= mx[0]; i[0]++) {
                    for (i[1] = mn[1]; i[1] <= mx[1]; i[1]++) {
                        for (i[2] = mn[2]; i[2] <= mx[2]; i[2]++) {
                            vector<int> pi = i;
                            dp[i[0]][i[1]][i[2]] = n + 1;
                            for (int j = 0; j < 3; j++) {
                                if (pi[j] > 0) {
                                    pi[j]--;
                                    upd(dp[i[0]][i[1]][i[2]], nxt[dp[pi[0]][pi[1]][pi[2]]][cur[j][i[j] - 1]] + 1);
                                    pi[j]++;
                                }
                            }
                        }
                    }
                }
            } else {
                len[id]--;
                cur[id].pop_back();
            }
            string res = dp[len[0]][len[1]][len[2]] <= n ? "YES" : "NO";
            cout << res << endl;
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}