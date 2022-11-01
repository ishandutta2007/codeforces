#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct e {
    int w, x, y, ei;

    bool operator<(const e &o) const {
        return w > o.w;
    }
};

struct uf {
    bool bp;
    int l[1000], c[1000];
    vector<e> v;

    void rst() {
        bp = true;
        FO(i,0,1000) l[i] = i, c[i] = 0;
    }

    int g(int i) {
        if (l[i] == i) return i;
        int nl = g(l[i]);
        c[i] ^= c[l[i]];
        return l[i] = nl;
    }

    void ue(e a) {
        if (!bp) return;
        if (g(a.x) != g(a.y)) {
            c[l[a.x]] = c[a.x] ^ c[a.y] ^ 1;
            l[l[a.x]] = l[a.y];
            v.push_back(a);
        } else {
            if (c[a.x] == c[a.y]) {
                bp = false;
                v.push_back(a);
                //printf("NOT BP\n");
            }
        }
    }
};

int n, m, q;
e el[500005];
int cp[500005];
int l[1005], r[1005];
vector<int> sp;

uf rt[4005];
uf tu;

int main() {
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,m) {
        scanf("%d %d %d", &el[i].x, &el[i].y, &el[i].w);
        el[i].x--; el[i].y--; el[i].ei = i;
    }
    sort(el,el+m);
    FO(i,0,q) {
        scanf("%d %d", l+i, r+i); l[i]--;
        sp.push_back(l[i]); sp.push_back(r[i]);
    }
    sp.push_back(0); sp.push_back(m); sp.push_back(m+1);
    sort(sp.begin(), sp.end());
    sp.resize(unique(sp.begin(),sp.end())-sp.begin());
    FO(i,0,sz(sp)-1) for (int j = sp[i]; j < sp[i+1]; j++)
        cp[j] = i;
    int rtn = sz(sp);
    FO(i,0,2*rtn) rt[i].rst();
    FO(i,0,m) {
        for (int j = rtn + cp[el[i].ei]; j > 0; j /= 2) {
            //printf("rt[%d]: %d,%d:%d\n", j,
                    //el[i].x, el[i].y, el[i].w);
            rt[j].ue(el[i]);
        }
    }
    FO(i,0,q) {
        int ql = cp[l[i]], qr = cp[r[i]];
        vector<e> v;
        for (ql += rtn, qr += rtn; ql < qr; ql /= 2, qr /= 2) {
            if (ql&1) v.insert(v.end(),
                    rt[ql].v.begin(), rt[ql].v.end()), ql++;
            if (qr&1) qr--, v.insert(v.end(),
                    rt[qr].v.begin(), rt[qr].v.end());
        }
        sort(v.begin(),v.end());
        tu.rst();
        int res = -1;
        for (auto ed : v) {
            tu.ue(ed);
            if (!tu.bp) {
                res = ed.w;
                break;
            }
        }
        printf("%d\n", res);
    }
}