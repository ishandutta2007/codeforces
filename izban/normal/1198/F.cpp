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

void print(vector<int> a) {
    if (a.empty()) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < (int)a.size(); i++) printf("%d%c", a[i] + 1, " \n"[i + 1 == (int)a.size()]);
    }
}

vector<int> fact(int x) {
    vector<int> pr;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            pr.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) pr.push_back(x);
    return pr;
}

vector<int> fix(vector<int> a) {
    map<int, int> mp;
    vector<int> res;
    for (int x : a) {
        if (++mp[x] <= 2) {
            res.push_back(x);
        }
    }
    return res;
}

mt19937 rnd(787788 ^ time(0));

vector<int> subsolve(vector<int> a) {
    auto oa = a;

    a = fix(a);
    shuffle(a.begin(), a.end(), rnd);

    auto gooda = a;

    vector<int> res;
    double start = clock() / (double)CLOCKS_PER_SEC;
    while (clock() / (double)CLOCKS_PER_SEC - start < 0.4) {
        a = gooda;
        shuffle(a.begin() + 1, a.end(), rnd);

        vector<int> cres(a.size());
        cres[1] = 1;
        int g0 = a[0], g1 = a[1];
        for (int i = 2; i < (int)a.size(); i++) {
            if (__gcd(g0, a[i]) != g0) {
                cres[i] = 0;
                g0 = __gcd(g0, a[i]);
            } else {
                cres[i] = 1;
                g1 = __gcd(g1, a[i]);
            }
        }
        if (g0 == 1 && g1 == 1) {
            res = cres;
            break;
        }
    }
    if (res.empty()) return res;

    map<int, vector<int>> mp;
    for (int i = 0; i < (int)oa.size(); i++) mp[oa[i]].push_back(i);

    vector<int> ans(oa.size());
    for (int i = 0; i < (int)a.size(); i++) {
        ans[mp[a[i]].back()] = res[i];
        mp[a[i]].pop_back();
    }
    return ans;
}

vector<int> solve(vector<int> a) {
    auto v = subsolve(a);
    if (!v.empty()) {
        int g0 = 0, g1 = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            if (v[i] == 0) g0 = __gcd(g0, a[i]);
            else g1 = __gcd(g1, a[i]);
        }
        assert(g0 == 1 && g1 == 1);
    }
    return v;
}

void test() {
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        print(solve(a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}