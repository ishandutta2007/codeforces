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

int solve(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();

    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i]) {
            auto b = a;
            b[i - 1]--;

            sort(b.begin(), b.end());
            for (int j = 1; j < n; j++) {
                if (b[j - 1] == b[j]) return 0;
            }
            for (int j = 0; j < n; j++) if (b[j] < 0) return 0;

            return !solve(b);
        }
    }

    a.insert(a.begin(), -1);

    vector<ll> dif(n);
    for (int i = 0; i < n; i++) dif[i] = a[i + 1] - a[i] - 1;

    ll turns = 0;
    for (int i = 0; i < n; i++) {
        turns += dif[i];
        if (i < n - 1) dif[i + 1] += dif[i];
    }
    return turns % 2 == 1;
}

void test() {

}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        string ans[2] = {"cslnb", "sjfnb"};
        cout << ans[solve(a)] << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}