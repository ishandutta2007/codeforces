#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

vector<int> v[1000007];
bool odw[1000007];
vector<int> ziomy[2];
int gl[100007];
bool juz[1000007];
int oj[1000007];

void dfs(int a, int moj, int mgl, bool kolor) {
    oj[a] = moj;
    odw[a] = true;
    gl[a] = mgl;
    oj[a] = moj;
    ziomy[kolor].push_back(a);
    for (auto it : v[a])
        if (!odw[it]) {
            dfs(it, a, mgl + 1, !kolor);
        }
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1, 1, false);
    sort(ziomy[0].begin(), ziomy[0].end(), [](int a, int b) {
        return gl[a] < gl[b];
    });
    sort(ziomy[1].begin(), ziomy[1].end(), [](int a, int b) {
        return gl[a] < gl[b];
    });
    vector<int> q = ziomy[0];
    if (ziomy[1].size() > ziomy[0].size())
        q = ziomy[1];
    int ile = (K + 1) / 2;
    for (int i = 0; i < ile; i++) {
        int a = q[i];
        juz[a] = true;
        for (auto it : v[a]) {
            if (juz[it]) {
                printf("2\n");
                vector<int> odp;
                while (a != it) {
                    odp.push_back(a);
                    a = oj[a];
                }
                odp.push_back(it);
                printf("%d\n", (int) odp.size());
                for (auto it2 : odp)
                    printf("%d ", it2);
                return 0;
            }
        }
    }
    printf("1\n");
    for (int i = 0; i < ile; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}