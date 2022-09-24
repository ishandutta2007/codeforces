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

const string Z[2] = {"Fou", "Shi"};
void print(vector<int> a) {
    for (int x : a) printf("%s\n", Z[x].c_str());
}

vector<int> solve(vector<int> a, vector<pair<int, int>> b) {
    int n = a.size();

    int mx = *max_element(a.begin(), a.end());
    int k = 0;
    while ((1 << k) <= mx) k++;

    vector<vector<int>> frst(n + 1, vector<int>(k, n));
    vector<int> last(k, n);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) if (a[i] & (1 << j)) {
            for (int l = 0; l < k; l++) {
                frst[i][l] = min(frst[i][l], frst[last[j]][l]);
            }
            last[j] = i;
        }
        for (int j = 0; j < k; j++) {
            if (a[i] & (1 << j)) {
                frst[i][j] = i;
            }
        }
    }
    vector<int> ans;
    for (auto o : b) {
        int ok = 0;

        int l = o.first;
        int r = o.second;
        for (int j = 0; j < k; j++) {
            if (a[r] & (1 << j)) {
                ok |= frst[l][j] <= r;
            }
        }
        ans.push_back(ok);
    }
    return ans;
}

void test() {
    int n = 3e5;
    vector<int> a(n, (1 << 18) - 1);
    int q = 3e5;
    vector<pair<int, int>> b(q);
    for (int i =0; i < q; i++) {
        b[i].first = rand() % (n - 1);
        b[i].second = rand() % (n - 1 - b[i].first) + b[i].first + 1;
//        db2(b[i].first, b[i].second);
        assert(0 <= b[i].first && b[i].first < b[i].second && b[i].second < n);
    }
    solve(a, b);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        vector<pair<int, int>> b(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &b[i].first, &b[i].second);
            b[i].first--;
            b[i].second--;
        }

        print(solve(a, b));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}