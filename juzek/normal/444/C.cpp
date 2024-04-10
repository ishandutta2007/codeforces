#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

struct Para {
    int a, b, kolor;

    bool operator<(Para const& p) const {
        return a < p.a;
    }
};

const int z = 1024 * 128;
long long drzewo[z * 2 + 7];
long long pomoc[z * 2 + 7];

void spychaj(int v) {
    drzewo[v * 2] += pomoc[v] / 2;
    drzewo[v * 2 + 1] += pomoc[v] / 2;
    pomoc[v * 2] += pomoc[v] / 2;
    pomoc[v * 2 + 1] += pomoc[v] / 2;
    pomoc[v] = 0;
}

void dodaj(int ll, int rr, int war, int v = 1, int l = 0, int r = z - 1) {
    if (l > rr || r < ll)
        return;
    if (ll <= l && r <= rr) {
        long long dl = r - l + 1;
        drzewo[v] += dl * war;
        pomoc[v] += dl * war;
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    dodaj(ll, rr, war, v * 2, l, sr);
    dodaj(ll, rr, war, v * 2 + 1, sr + 1, r);
    drzewo[v] = drzewo[v * 2] + drzewo[v * 2 + 1];
}

long long ret = 0;

void czytaj(int ll, int rr, int v = 1, int l = 0, int r = z - 1) {
    if (l > rr || r < ll)
        return;
    if (ll <= l && r <= rr) {
        ret += drzewo[v];
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    czytaj(ll, rr, v * 2, l, sr);
    czytaj(ll, rr, v * 2 + 1, sr + 1, r);
}

std::set<Para> s;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N + 1; i++)
        s.insert({i, i, i});
    int type, a, b, c;
    while (M--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &a, &b, &c);
            auto it = --s.upper_bound({a, 0, 0});
            if (it->a < a) {
                auto val = *it;
                s.erase(it);
                s.insert({val.a, a - 1, val.kolor});
                s.insert({a, val.b, val.kolor});
            }
            auto it2 = --s.upper_bound({b, 0, 0});
            if (it2->b > b) {
                auto val = *it2;
                s.erase(it2);
                s.insert({val.a, b, val.kolor});
                s.insert({b + 1, val.b, val.kolor});
            }
            it = s.lower_bound({a, 0, 0});
            while (it->b <= b) {
                auto val = *it;
                dodaj(val.a, val.b, std::abs(val.kolor - c));
                it = s.erase(it);
            }
            s.insert({a, b, c});
        } else {
            scanf("%d%d", &a, &b);
            ret = 0;
            czytaj(a, b);
            printf("%lld\n", ret);
        }
    }
    return 0;
}