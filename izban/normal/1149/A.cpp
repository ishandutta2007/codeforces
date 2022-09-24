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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int m = 0;
        vector<int> cnt(3);
        for (int x : a) {
            m += x;
            cnt[x]++;
        }

        vector<int> ispr(m + 1, 1);
        ispr[1] = 0;
        for (int i = 2; i <= m; i++) {
            for (int j = i + i; j <= m; j += i) {
                ispr[j] = 0;
            }
        }

        sort(a.begin(), a.end());
        if (cnt[1] > 0 && cnt[2] > 0) {
            a.clear();
            a.push_back(2);
            cnt[2]--;
            a.push_back(1);
            cnt[1]--;
            while (cnt[2]) {
                a.push_back(2);
                cnt[2]--;
            }
            while (cnt[1]) {
                a.push_back(1);
                cnt[1]--;
            }
        }

        int res = 0;
        int cur = 0;
        for (int x : a) {
            cur += x;
            res += ispr[cur];
        }

        for (int x : a) printf("%d ", x);
        printf("\n");
//        db(res);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}