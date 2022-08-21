#include <bits/stdc++.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
using namespace std;

#define N 311111
#define INF (1<<30)
#define Q N
#define S 550

struct que {
    int l, r, k, idx, ans;
    bool operator<(const que& other) const {
        int lS = l / S;
        int olS = other.l / S;
        return lS != olS ? lS < olS : r < other.r;
    }
};
int a[N];

que qs[Q];
int anses[Q];

#define D 6
int mostv[D+1];
int mosti[D+1];
int mostc[D+1];
int ct[N];

vector<int> pos[N];
int where[N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < pos[i].size(); j++) {
            where[pos[i][j]] = j;
        }
    }
}

int kth(int j, int k) {
    int w = where[j];
    assert(pos[a[j]][w] == j);
    if (w + k < pos[a[j]].size()) {
        return pos[a[j]][w + k];
    }
    return INF;
}

void trycand(int i, int j) {
    if (!(qs[i].l <= j && j < qs[i].r)) return;
    // printf("trying %d %d\n", i, j);
    int want = (qs[i].r - qs[i].l) / qs[i].k;
    int J = kth(j, want);
    // printf("want = %d, J = %d\n", want, J);
    if (J < qs[i].r) {
        qs[i].ans = min(qs[i].ans, a[j]);
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &qs[i].l, &qs[i].r, &qs[i].k);
        qs[i].idx = i;
        qs[i].ans = INF;
        qs[i].l--;
    }
    sort(qs, qs + q);

    init(n);

    for (int s = S, l = 0; s < n; s += S) {

        // fprintf(stderr, "s = %d\n", s);
        // int r = l;
        // while (r < q && qs[r].l < s) r++;
        // for (int w = l + 1; w < r; w++) {
        //     assert(qs[w - 1].r <= qs[w].r);
        // }
        // for (int w = l; w < r; w++) {
        //     fprintf(stderr, "%d: %d %d\n", w, qs[w].l, qs[w].r);
        // }
        for (int i = 0; i < D; i++) {
            mostv[i] = -1;
            // mosti[i] = -1;
            mostc[i] = 0;
        }
        for (int i = 0; i <= n; i++) ct[i] = 0;
        for (int i = s; i < n; i++) {
            mostv[D] = a[i];
            mosti[D] = i;
            mostc[D] = ct[a[i]]++;
            int j = 0;
            while (mostv[j] != a[i]) j++;
            mostc[j]++;
            while (j > 0 && mostc[j - 1] < mostc[j]) {
                swap(mostv[j], mostv[j - 1]);
                // swap(mosti[j], mosti[j - 1]);
                swap(mostc[j], mostc[j - 1]);
                j--;
            }

            while (l < q && qs[l].l < s && qs[l].r - 1 <= i) {
                // fprintf(stderr, "trying l = %d (%d %d)\n", l, qs[l].l, qs[l].r);
                for (int k = 0; k < D; k++) {
                    // fprintf(stderr, "hoy %d\n", mosti[k]);
                    // trycand(l, mosti[k]);
                    if (i < qs[l].r && mostc[k] * qs[l].k > qs[l].r - qs[l].l) {
                        qs[l].ans = min(qs[l].ans, mostv[k]);
                    }
                }
                l++;
            }
            // fprintf(stderr, "hoy i=%d, l=%d\n", i, l);
        }
        // fprintf(stderr, "l=%d, r=%d\n", l, r);
        // assert(l == r);
        // assert(!(l < q && qs[l].l < s));
    }
    for (int i = 0; i < q; i++) {
        int targ = (qs[i].l + S) / S * S + 11;
        assert(targ >= qs[i].l);
        for (int j = qs[i].l; j <= targ && j < qs[i].r; j++) {
            trycand(i, j);
        }
        // for (int j = qs[i].l; j <= qs[i].l + S && j < qs[i].r; j++) {
        //     trycand(i, j);
        // }
    }

    for (int i = 0; i < q; i++) {
        anses[qs[i].idx] = qs[i].ans < INF ? qs[i].ans : -1;
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", anses[i]);
    }
}