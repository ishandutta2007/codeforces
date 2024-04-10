#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;

const int MAXN = 200005;
const int INF = 1000000000;

int n, q, cnt, root;
pi p[MAXN], u[MAXN];
int lef[MAXN], rig[MAXN], prior[MAXN];
int ind[MAXN], val[MAXN], p_val[MAXN], sol[MAXN], p_sol[MAXN], ans[MAXN];
vector <int> v;

void propagate (int x) {
    if (x == 0) return;
    if (p_val[x] != 0) {
        if (lef[x]) p_val[lef[x]] += p_val[x];
        if (rig[x]) p_val[rig[x]] += p_val[x];
        val[x] += p_val[x];
        p_val[x] = 0;
    }
    if (p_sol[x] != 0) {
        if (lef[x]) p_sol[lef[x]] += p_sol[x];
        if (rig[x]) p_sol[rig[x]] += p_sol[x];
        sol[x] += p_sol[x];
        p_sol[x] = 0;
    }
}

void spoji (int &t, int l, int r) {
    propagate(l); propagate(r);
    if (l == 0 || r == 0) {
        if (l != 0) t = l; else t = r;
    } else if (prior[l] > prior[r]) {
        spoji(rig[l], rig[l], r); t = l;
    } else {
        spoji(lef[r], l, lef[r]); t = r;
    }
}

void split (int t, int k, int & l, int & r) {
    propagate(t);
    if (t == 0) {
        l = r = 0;
        return;
    }
    if (k <= val[t]) {
        split(lef[t], k, l, lef[t]); r = t;
    } else {
        split(rig[t], k, rig[t], r); l = t;
    }
}

void ubaci (int &t, int novi) {
    propagate(t);
    if (t == 0) {
        t = novi;
    } else if (prior[novi] > prior[t]) {
        split(t, val[novi], lef[novi], rig[novi]); t = novi;
    } else {
        if (val[novi] <= val[t]) ubaci(lef[t], novi); else ubaci(rig[t], novi);
    }
}

void prodi (int t) {
    propagate(t);
    if (t == 0) return;
    prodi(lef[t]);
    v.push_back(t);
    prodi(rig[t]);
}

void debug (int t, int dub) {
    for (int i = 0; i < dub; i++) cout << " ";
    cout << t << " " << val[t] << " " << sol[t] << endl;
    if (t == 0) return;
    debug(lef[t], dub + 1);
    debug(rig[t], dub + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
        p[i].first *= -1;
    }
    sort(p, p + n);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u[i].first;
        u[i].second = i;
    }
    sort(u, u + q);
    for (int i = 0; i < q; i++) {
        cnt++;
        val[cnt] = u[i].first;
        ind[cnt] = u[i].second;
        prior[cnt] = uniform_int_distribution <int> (0, INF)(rng);
        spoji(root, root, cnt);
    }
    for (int i = 0; i < n; i++) {
        int w = p[i].second;
        int jen, dva, tri;

        split(root, w, jen, root);
        if (root) {
            p_sol[root]++; p_val[root] -= w;
            propagate(root);
        }
        split(root, w, dva, tri);

        v.clear();
        prodi(dva);
        for (auto x : v) {
            lef[x] = rig[x] = 0;
            ubaci(jen, x);
        }

        spoji(root, jen, tri);
    }
    prodi(root);
    for (int i = 1; i <= q; i++) {
        ans[ind[i]] = sol[i];
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}