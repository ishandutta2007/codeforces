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


const ll INF = 4e9;

void print(vector<int> a) {
    printf("%d\n", (int)a.size());
    for (int i = 0; i <( int)a.size(); i++) printf("%d%c", a[i] + 1, " \n"[i + 1== (int)a.size()]);
}

vector<int> solve(vector<pair<int, int>> a) {
    int n = a.size();
    vector<int> ans;

    for (int it = 0; it < 2; it++) {
        vector<int> vct;
        for (int i = 0; i < n; i++) {
            if (a[i].first < a[i].second) {
                vct.push_back(i);
            }
        }
        sort(vct.begin(), vct.end(), [&](int i, int j) {
           return a[i].second > a[j].second;
        });

        if (ans.size() < vct.size()) {
            ans = vct;
        }

        for (int i = 0; i < n; i++) {
//            swap(a[i].first, a[i].second);
            a[i].first *= -1;
            a[i].second *= -1;
        }
    }

    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
            a[i].first--;
            a[i].second--;
        }

        print(solve(a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}