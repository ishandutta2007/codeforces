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

int pytaj(int a, int b) {
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v;
    for (int i = 1; i <= N; i++)
        v.push_back(i);
    random_shuffle(v.begin(), v.end());
    int a = v[0], b = v[1];
    int teraz = pytaj(a, b);
    for (int i = 2; i < N; i++) {
        int c = v[i];
        int hmm = pytaj(b, c);
        if (hmm > teraz)
            continue;
        if (hmm < teraz) {
            a = c;
            teraz = hmm;
            continue;
        }
        b = c;
        teraz = pytaj(a, b);
    }
    int ktory = -1;
    for (auto it : v) {
        if (it == a || it == b)
            continue;
        int a1 = pytaj(it, a);
        int b1 = pytaj(it, b);
        if (a1 < b1) {
            ktory = a;
            break;
        } else if (b1 < a1) {
            ktory = b;
            break;
        }
    }
    vector<int> odp;
    for (int i = 1; i <= N; i++) {
        if (i != ktory)
            odp.push_back(pytaj(i, ktory));
        else
            odp.push_back(0);
    }
    printf("! ");
    for (auto it : odp)
        printf("%d ", it);
    return 0;
}