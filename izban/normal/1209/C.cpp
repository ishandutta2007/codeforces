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



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        const int N = 1.01e6;
        static char buf[N];
        scanf("%d %s", &n, buf);
        string s = buf;

        vector<vector<int>> pos(10);
        for (int i = 0; i < n; i++) {
            pos[s[i] - '0'].push_back(i);
        }

        vector<int> vct;
        int last = -1;
        for (int c = 0; c < 10; c++) {
            int j = 0;
            while (j < (int)pos[c].size() && pos[c][j] <= last) j++;

            for (int i = j; i < (int)pos[c].size(); i++) {
                vct.push_back(pos[c][i]);
            }
            for (int i = 0; i < j; i++) {
                vct.push_back(pos[c][i]);
            }
            last = vct.empty() ? -1 : vct.back();
        }

        string ans(n, '0');
        int cnt = 0;
        last = -1;

        for (int x : vct) {
            if (x < last) {
                cnt++;
                if (cnt >= 2) {
                    ans = "-";
                    break;
                }
            }
            ans[x] = '1' + cnt;
            last = x;
        }


        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}