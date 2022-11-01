#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 2048;


typedef bitset<maxn> B;

int n;

int R(int x) {
    return x^1;
}

void SIM() {
    cout << "SIMILAR" << endl;
    exit(0);
}

B a1[maxn], a2[maxn];
int s1[maxn], s2[maxn];

void NONSIM(int s[]) {
    forn(i, n) {
        printf("%d ", s[i]^1);
    }
    printf("\n");
    exit(0);
}

void readf(int m, B a[]) {
    forn(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        {
        bool add = x < 0;
        if (x < 0) x = -x;
        --x;
        x = x * 2 + add;
        }

        {
        bool add = y < 0;
        if (y < 0) y = -y;
        --y;
        y = y * 2 + add;
        }

//         cerr << x << " v " << y << endl;

        a[R(x)][y] = 1;
        a[R(y)][x] = 1;
    }

    forn(i, n*2) {
        a[i][i] = 1;
    }
}

void scan() {
    int m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    readf(m1, a1);
    readf(m2, a2);
}

void closure(B a[]) {
    forn(k, n*2) {
        forn(i, n*2) if (a[i][k]) {
            a[i] |= a[k];
        }
    }
}

void take(B a[], int s[], int x) {
    assert(s[x/2] == -1);
    s[x/2] = x&1;
    forn(i, n*2) if (s[i/2] == -1 && a[x][i]) {
        take(a, s, i);
    }
    a[x].reset();
    a[x^1].reset();
    forn(i, n*2) {
        a[i][x] = a[i][x^1] = 0;
    }
}

// return false if no solution present
bool reduct(B a[], int s[]) {
    // check
    for (int i = 0; i < n*2; i += 2) {
        if (a[i][i^1] && a[i^1][i]) {
            return false;
        }
    }

    // reduct
    for (int i = 0; i < n*2; i += 2) {
        if (a[i][i^1] && a[i^1][i]) {
            return false;
        }
        if (a[i][i^1]) take(a, s, i^1);
        else if (a[i^1][i]) take(a, s, i);
    }

    return true;
}

void solve_full(B a[], int s[]) {
    forn(i, n*2) if (s[i/2] == -1) {
        take(a, s, i);
    }
}

void solve() {
    scan();

    memset(s1, -1, sizeof s1);
    memset(s2, -1, sizeof s2);

    closure(a1);
    closure(a2);

    bool res1 = reduct(a1, s1);
    bool res2 = reduct(a2, s2);

//     cerr << "sat: " << res1 << " " << res2 << endl;
//     NONSIM(s1);
//     NONSIM(s2);

    if (!res1 && !res2) {
        SIM();
    } else if (res1 != res2) {
        if (res1) {
            solve_full(a1, s1);
            NONSIM(s1);
        } else {
            solve_full(a2, s2);
            NONSIM(s2);
        }
    }

//     cerr << "pre 1: "; forn(i, n) cerr << s1[i] << " "; cerr << endl;
//     cerr << "pre 1: "; forn(i, n) cerr << s2[i] << " "; cerr << endl;

    forn(i, n) if (s1[i] != -1 && s2[i] != -1 && s1[i] != s2[i]) {
        solve_full(a1, s1);
        NONSIM(s1);
    }

//     cerr << "got here" << endl;

    forn(i, n) if (s1[i] != s2[i]) {
        if (s1[i] == -1) {
            take(a1, s1, i*2 + !s2[i]);
            solve_full(a1, s1);
            NONSIM(s1);
        } else {
            take(a2, s2, i*2 + !s1[i]);
            solve_full(a2, s2);
            NONSIM(s2);
        }
    }

    // normal solution goes here

    forn(i, n*2) forn(j, n*2) if (s1[i/2] == -1 && s1[j/2] == -1) {
        if (a1[i][j] != a2[i][j]) {
            if (a1[i][j]) {
//                 cerr << "take in 2: " << i << " " << j << endl;
                take(a2, s2, i);
                if (s2[j/2] == -1) take(a2, s2, j^1);
                solve_full(a2, s2);
                NONSIM(s2);
            } else {
//                 cerr << "take in 1: " << i << " " << j << endl;
                take(a1, s1, i);
                if (s1[j/2] == -1) take(a1, s1, j^1);
                solve_full(a1, s1);
                NONSIM(s1);
            }
        }
    }

    SIM();
}

int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}