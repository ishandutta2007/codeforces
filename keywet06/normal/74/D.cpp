#include <bits/stdc++.h>

using namespace std;

const int N = 500000;
int n, q;
int t[N], l[N], r[N];
int p[N];

void update(int k, int delta) {
    for (int i = k; i < N; i |= (i + 1)) p[i] += delta;
}

int get(int k) {
    int res = 0;
    for (int i = k; i >= 0; i = (i & (i + 1)) - 1) res += p[i];
    return res;
}

int get(int l, int r) { return get(r) - get(l - 1); }

set<pair<int, pair<int, int> > > segs;
set<pair<int, int> > byLeft;
set<pair<int, int> > byRight;

map<int, int> pos;

int id[N];

void remove(int value, set<pair<int, int> > *S) {
    set<pair<int, int> >::iterator it = S->lower_bound(make_pair(value, -1));
    if (it == S->end()) return;
    if (it->first == value) S->erase(it);
}

pair<int, int> find(int value, set<pair<int, int> > *S) {
    set<pair<int, int> >::iterator it = S->lower_bound(make_pair(value, -1));
    if (it == S->end() || it->first != value) return make_pair(-1, -1);
    return *it;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &t[i]);
        if (t[i] == 0) scanf("%d%d", &l[i], &r[i]);
    }
    segs.insert(make_pair(-n, make_pair(-1, n)));
    byLeft.insert(make_pair(1, n));
    byRight.insert(make_pair(n, 1));
    for (int i = 1; i <= q; ++i) {
        if (t[i] == 0) continue;
        if (pos[t[i]] != 0) {
            int m = pos[t[i]];
            pair<int, int> R = find(m + 1, &byLeft);
            pair<int, int> L = find(m - 1, &byRight);
            swap(L.first, L.second);
            if (L.first == -1 && R.first == -1) {
                segs.insert(make_pair(-1, make_pair(-m, m)));
                byLeft.insert(make_pair(m, m));
                byRight.insert(make_pair(m, m));
            } else if (L.first == -1 && R.first != -1) {
                segs.erase(make_pair(-(R.second - R.first + 1),
                                     make_pair(-R.first, R.second)));
                segs.insert(
                    make_pair(-(R.second - m + 1), make_pair(-m, R.second)));
                remove(R.first, &byLeft);
                remove(R.second, &byRight);
                byLeft.insert(make_pair(m, R.second));
                byRight.insert(make_pair(R.second, m));
            } else if (L.first != -1 && R.first == -1) {
                segs.erase(make_pair(-(L.second - L.first + 1),
                                     make_pair(-L.first, L.second)));
                segs.insert(
                    make_pair(-(m - L.first + 1), make_pair(-L.first, m)));
                remove(L.first, &byLeft);
                remove(L.second, &byRight);
                byLeft.insert(make_pair(L.first, m));
                byRight.insert(make_pair(m, L.first));
            } else {
                segs.erase(make_pair(-(R.second - R.first + 1),
                                     make_pair(-R.first, R.second)));
                segs.erase(make_pair(-(L.second - L.first + 1),
                                     make_pair(-L.first, L.second)));
                remove(R.first, &byLeft);
                remove(R.second, &byRight);
                remove(L.first, &byLeft);
                remove(L.second, &byRight);
                segs.insert(make_pair(-(R.second - L.first + 1),
                                      make_pair(-L.first, R.second)));
                byLeft.insert(make_pair(L.first, R.second));
                byRight.insert(make_pair(R.second, L.first));
            }
            pos[t[i]] = 0;
            id[i] = m;
        } else {
            pair<int, pair<int, int> > seg = *segs.begin();
            segs.erase(segs.begin());
            int l = -seg.second.first;
            int r = seg.second.second;
            int m = (l + r + 1) / 2;
            if (l <= m - 1) {
                segs.insert(make_pair(-(m - l), make_pair(-l, m - 1)));
            }
            if (m + 1 <= r) {
                segs.insert(make_pair(-(r - m), make_pair(-(m + 1), r)));
            }
            remove(l, &byLeft);
            remove(r, &byRight);
            if (l <= m - 1) {
                byLeft.insert(make_pair(l, m - 1));
                byRight.insert(make_pair(m - 1, l));
            }
            if (r >= m + 1) {
                byLeft.insert(make_pair(m + 1, r));
                byRight.insert(make_pair(r, m + 1));
            }
            pos[t[i]] = m;
            id[i] = m;
        }
    }

    vector<int> a;
    for (int i = 1; i <= q; ++i) {
        if (t[i] == 0) {
            a.push_back(l[i]);
            a.push_back(r[i]);
        } else {
            a.push_back(id[i]);
        }
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    for (int i = 1; i <= q; ++i) {
        if (t[i] == 0) {
            l[i] = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
            r[i] = lower_bound(a.begin(), a.end(), r[i]) - a.begin();
        } else {
            id[i] = lower_bound(a.begin(), a.end(), id[i]) - a.begin();
        }
    }

    for (int i = 1; i <= q; ++i) {
        if (t[i] == 0) {
            printf("%d\n", get(l[i], r[i]));
        } else {
            int value = get(id[i], id[i]);
            if (value == 1) {
                update(id[i], -1);
            } else {
                update(id[i], +1);
            }
        }
    }

    return 0;
}