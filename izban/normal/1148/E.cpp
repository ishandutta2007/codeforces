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

struct Move {
    int i, j, d;
};

void print(vector<Move> a) {
    if (a.size() == 1 && a[0].d == -1) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("%d\n", (int) a.size());
        for (auto o : a) {
            printf("%d %d %d\n", o.i + 1, o.j + 1, o.d);
        }
    }
}

auto FAIL = vector<Move>(1, {-1, -1, -1});

vector<Move> solve(vector<int> _a, vector<int> _b) {
    int n = _a.size();
    vector<Move> ans;

    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = {_a[i], i};
        b[i] = {_b[i], i};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        if (a[i].first < b[i].first) {
            v1.push_back(i);
        } else if (a[i].first > b[i].first) {
            v2.push_back(i);
        }
    }

    int j = 0;
    for (int i = 0; i < (int)v1.size(); i++) {
        while (a[v1[i]].first < b[v1[i]].first) {
            int d1 = b[v1[i]].first - a[v1[i]].first;

            while (j < (int)v2.size() && a[v2[j]].first == b[v2[j]].first) {
                j++;
            }
            if (j == (int)v2.size()) return FAIL;
            int d2 = a[v2[j]].first - b[v2[j]].first;

            if (v1[i] > v2[j]) {
                return FAIL;
            }

            int d = min(d1, d2);
            a[v1[i]].first += d;
            a[v2[j]].first -= d;
            ans.push_back({a[v1[i]].second, a[v2[j]].second, d});
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i].first != b[i].first) {
            return FAIL;
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        print(solve(a, b));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}