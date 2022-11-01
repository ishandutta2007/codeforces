#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct rng {
    int l, r, amt;

    rng(int l, int r, int amt) : l(l), r(r), amt(amt) {}
};

int n, d, b;
int a[100005];
vector<rng> st;
int split;

bool canr(int i, int t) {
    int nmnd = (abs(i-t) + d - 1) / d;
    if (t < split) {
        return nmnd <= t+1;
    } else {
        return nmnd <= n-t;
    }
}

bool cmpfh(const rng &x, const rng &y) {
    if (x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}

bool cmplh(const rng &x, const rng &y) {
    if (x.r != y.r) return x.r > y.r;
    return x.l > y.l;
}

bool can(int nf) {
    int need = max(0,split - nf);
    vector<rng> remst = st;
    sort(remst.begin(), remst.end(), cmpfh);
    int invi = 0;
    int csi = 0;
    int nmhav = 0;
    fo(i,0,split) if (need) {
        //printf("i=%d\n", i);
        while (csi < sz(remst) && remst[csi].l <= i) {
            nmhav += remst[csi].amt;
            csi++;
        }
        while (invi < csi && remst[invi].r < i) {
            nmhav -= remst[invi].amt;
            invi++;
        }
        //printf("nmhav = %d\n", nmhav);
        if (nmhav >= b) {
            nmhav -= b;
            int ndget = b;
            while (ndget > 0) {
                int x = min(remst[invi].amt, ndget);
                remst[invi].amt -= x;
                ndget -= x;
                if (remst[invi].amt == 0) invi++;
            }
            need--;
        }
    }
    if (need) return false;

    need = max(0, n-split-nf);
    sort(remst.begin(), remst.end(), cmplh);
    //for (auto r : remst) printf("[%d,%d]*%d\n", r.l, r.r, r.amt);
    invi = 0;
    csi = 0;
    nmhav = 0;
    for (int i = n-1; i >= split; i--) if (need) {
        //printf("i=%d\n", i);
        while (csi < sz(remst) && remst[csi].r >= i) {
            nmhav += remst[csi].amt;
            csi++;
        }
        while (invi < sz(remst) && remst[invi].l > i) {
            nmhav -= remst[invi].amt;
            invi++;
        }
        //printf("nmhav = %d\n", nmhav);
        if (nmhav >= b) {
            nmhav -= b;
            int ndget = b;
            while (ndget > 0) {
                int x = min(remst[invi].amt, ndget);
                remst[invi].amt -= x;
                ndget -= x;
                if (remst[invi].amt == 0) invi++;
            }
            need--;
        }
    }
    if (need) return false;
    return true;
}

int main() {
    scanf("%d %d %d", &n, &d, &b);
    split = (n + 1)/2;
    fo(i,0,n) {
        scanf("%d", a+i);

        int s = 0, e = i, lbst = i;
        while (s <= e) {
            int md = (s+e)/2;
            if (canr(i, md)) {
                lbst = md;
                e = md-1;
            } else s = md+1;
        }

        s = i, e = n-1;
        int rbst = i;
        while (s <= e) {
            int md = (s+e)/2;
            if (canr(i, md)) {
                rbst = md;
                s = md+1;
            } else e = md-1;
        }
        st.emplace_back(lbst, rbst, a[i]);
        //printf("%d: [%d,%d] * %d\n", i, lbst, rbst, a[i]);
    }
    int s = 0, e = n, bst = n;
    while (s <= e) {
        int md = (s+e)/2;
        if (can(md)) {
            bst = md;
            e = md-1;
        } else s = md+1;
    }
    //printf("can(%d)=%d\n", 1, can(1));
    printf("%d\n", bst);

}