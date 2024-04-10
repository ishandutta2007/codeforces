#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct f {
    ll a, b;
    int i;

    bool operator<(const f &o) const {
        if (a*o.b == b*o.a) return i < o.i;
        return a*o.b < b*o.a;
    }
};

int n, t, q;
int p[200005];
int l[200005];
int o[200005];
int so;

set<f> used;
set<f> canuse;

long double cv;

f getf(int i, int v) {
    // frac for v over v-1
    f tmp1;
    tmp1.a = v*p[i];
    tmp1.b = l[i]+v;

    f tmp2;
    tmp2.a = (v-1)*p[i];
    tmp2.b = l[i]+(v-1);

    f tmp;
    tmp.a = tmp1.a * tmp2.b - tmp2.a * tmp1.b;
    tmp.b = tmp1.b * tmp2.b;
    tmp.i = i;
    return tmp;
}

void remus(int i) {
    // our used
    if (o[i]) {
        f tmp = getf(i, o[i]);
        auto it = used.find(tmp);
        if (it != used.end()) used.erase(it);
    }
    // our canuse
    if (o[i] < l[i]) {
        f tmp = getf(i, o[i]+1);
        auto it = canuse.find(tmp);
        if (it != canuse.end()) canuse.erase(it);
    }
}

void addus(int i) {
    // our used
    if (o[i]) {
        f tmp = getf(i, o[i]);
        used.insert(tmp);
    }
    // our canuse
    if (o[i] < l[i]) {
        f tmp = getf(i, o[i]+1);
        canuse.insert(tmp);
    }
}

void remcon(int i) {
    cv -= p[i] * o[i] / 1.L / (l[i]+o[i]);
}

void addcon(int i) {
    cv += p[i] * o[i] / 1.L / (l[i]+o[i]);
}

void osmosis() {
    while (sz(canuse) && so < t) {
        int i = canuse.rbegin()->i;
        remus(i);
        remcon(i);
        o[i]++; so++;
        addcon(i);
        addus(i);
    }
    while (sz(canuse) && sz(used)) {
        if (*used.begin() < *canuse.rbegin()) {
            // unuse it
            int i = used.begin()->i, j = canuse.rbegin()->i;
            remus(i);
            remcon(i);
            remus(j);
            remcon(j);
            o[i]--; o[j]++;
            addcon(j);
            addus(j);
            addcon(i);
            addus(i);
        } else break;
    }
}

int main() {
    scanf("%d%d%d", &n, &t, &q);
    FO(i,0,n) {
        scanf("%d", p+i);
    }
    FO(i,0,n) {
        scanf("%d", l+i);
    }
    FO(i,0,n) {
        remus(i);
        addus(i);
    }
    osmosis();
    FO(z,0,q) {
        int t, i; scanf("%d%d", &t, &i); i--;
        if (t == 1) {
            // add ticket
            remus(i);
            remcon(i);
            l[i]++;
            addcon(i);
            addus(i);
        } else {
            // remove ticket
            remus(i);
            remcon(i);
            l[i]--;
            while (o[i] > l[i]) {
                o[i]--; so--;
            }
            addcon(i);
            addus(i);
        }
        osmosis();
        double ans = cv;
        printf("%.9lf\n", ans);
    }
}