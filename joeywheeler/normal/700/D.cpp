#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct hfcd {
    int vl[200005], f[100005], l[100005];
    int frq[100005];
    int ne;
    int ts;

    hfcd() {
        f[0] = 0;
        l[0] = 200002;
        ne = 0;
        ts = 0;
    }

    int clcv() {
        return ts - ne - vl[l[0]+1];
    }

    void addsym(int x) {
        ne++;

        int of = frq[x]++;
        int inci = l[of];
        if (l[of] == l[0] || l[of] == l[0]+2) {
            add(of); add(of);
        } else {
            add(of);
        }
        while (inci != 200002) {
            int nv = vl[inci] + vl[inci^1];
            inci = l[nv-1];
            add(nv-1);
        }
    }

    void delsym(int x) {
        ne--;

        int of = frq[x]--;
        int dci = f[of];
        if (vl[l[0]+1] == of) {
            dci = l[0]+2;
            rem(of); rem(of);
        } else {
            rem(of);
        }
        while (dci != 200002) {
            int nv = vl[dci] + vl[dci^1];
            dci = f[nv+1];
            rem(nv+1);
        }
    }

    void add(int x) {
        // inc an x
        int i = l[x];
        vl[i]++;
        l[x]--;
        f[x+1] = i;
        if (vl[l[x+1]] != x+1) l[x+1] = i;

        ts++;
    }

    void rem(int x) {
        int i = f[x];
        vl[i]--;
        f[x]++;
        l[x-1] = i;
        if (vl[f[x-1]] != x-1) f[x-1] = i;

        ts--;
    }
} hf;

#define MGC 316

int n, q;
int ql[100005], qr[100005], qa[100005], qo[100005];
int v[100005];

bool qc(int i, int j) {
    if (ql[i]/MGC != ql[j]/MGC) return ql[i] < ql[j];
    return qr[i] < qr[j];
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", v+i);
    scanf("%d", &q);
    FO(i,0,q) {
        scanf("%d %d", ql+i, qr+i);
        ql[i]--;
        qo[i] = i;
    }
    sort(qo,qo+q,qc);
    int cl = 0, cr = 0;
    FO(i,0,q) {
        int l = ql[qo[i]], r = qr[qo[i]];
        while (cr < r) hf.addsym(v[cr++]);
        while (cl > l) hf.addsym(v[--cl]);
        while (cr > r) hf.delsym(v[--cr]);
        while (cl < l) hf.delsym(v[cl++]);
        qa[qo[i]] = hf.clcv();
    }
    FO(i,0,q) printf("%d\n", qa[i]);
}