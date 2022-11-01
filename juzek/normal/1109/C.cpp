#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <set>

const int ROZM = 100007;
const int z = 1024 * 256;

int T[ROZM], A[ROZM], B[ROZM], C[ROZM];
std::vector<int> punkty;
std::map<int, int> pozycja;
std::map<int, int> realne;

long long mini[z * 2 + 7], pomoc[z * 2 + 7];

void spychaj(int v) {
    if (pomoc[v] == 0)
        return;
    pomoc[v * 2] += pomoc[v];
    pomoc[v * 2 + 1] += pomoc[v];
    mini[v * 2] += pomoc[v];
    mini[v * 2 + 1] += pomoc[v];
    pomoc[v] = 0;
}

void dodaj(int ll, int rr, long long war, int v = 1, int l = 1, int r = z) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        mini[v] += war;
        pomoc[v] += war;
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    dodaj(ll, rr, war, v * 2, l, sr);
    dodaj(ll, rr, war, v * 2 + 1, sr + 1, r);
    mini[v] = std::min(mini[v * 2], mini[v * 2 + 1]);
}

long long wynikCzytania = LLONG_MAX;

void czytaj(int ll, int rr, int v = 1, int l = 1, int r = z) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        wynikCzytania = std::min(wynikCzytania, mini[v]);
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    czytaj(ll, rr, v * 2, l, sr);
    czytaj(ll, rr, v * 2 + 1, sr + 1, r);
    mini[v] = std::min(mini[v * 2], mini[v * 2 + 1]);
}

int dodalem[z];

long long drzewo[z];

void dodajSuf(int a, long long war) {
//    printf("Dodaje na suffiksie od %d wartosc %lld\n", a, war);
    while (a < z) {
        drzewo[a] += war;
        a += (a & -a);
    }
}

long long czytajPref(int a) {
    long long ret = 0;
    while (a > 0) {
        ret += drzewo[a];
        a -= (a & -a);
    }
    return ret;
}

std::set<int> dodaneAktualnie;

int main() {
    int Q;
    scanf("%d", &Q);
    punkty.push_back(-1);
    punkty.push_back(1337133713);
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &T[i]);
        if (T[i] == 1) {
            scanf("%d%d", &A[i], &B[i]);
            punkty.push_back(A[i]);
        } else if (T[i] == 2) {
            scanf("%d", &A[i]);
        } else {
            scanf("%d%d%d", &A[i], &B[i], &C[i]);
            punkty.push_back(A[i]);
            punkty.push_back(B[i]);
        }
    }
    std::sort(punkty.begin(), punkty.end());
    int poprz = -1337;
    int zeit = 0;
    for (auto it : punkty)
        if (it != poprz) {
            pozycja[it] = ++zeit;
            realne[zeit] = it;
//            printf("%d -> %d\n", it, zeit);
            poprz = it;
        }
    dodaneAktualnie.insert(pozycja[-1]);
    dodaneAktualnie.insert(pozycja[1337133713]);
    dodalem[pozycja[-1]] = 0;
    for (int i = 1; i <= Q; i++) {
        if (T[i] == 1) {
            int pos = pozycja[A[i]];
            poprz = *(--dodaneAktualnie.upper_bound(pos));
            int nast = *dodaneAktualnie.lower_bound(pos);
            long long odejme = (long long) (-realne[nast] + realne[poprz] + A[i] - realne[poprz]) * dodalem[poprz];
            long long dodam = realne[nast] - A[i];
            dodam *= B[i];

            dodaj(pos, zeit, dodam);
            dodajSuf(pos, dodam);

            dodaj(poprz, zeit, odejme);
            dodajSuf(poprz, odejme);

            dodalem[pos] = B[i];

            dodaneAktualnie.insert(pos);
        } else if (T[i] == 2) {
            int pos = pozycja[A[i]];
            poprz = *(--dodaneAktualnie.lower_bound(pos));
            int nast = *dodaneAktualnie.upper_bound(pos);

            long long dodam = (long long) (-A[i] + realne[poprz] + realne[nast] - realne[poprz]) * dodalem[poprz];

            long long odejme = realne[nast] - A[i];
            odejme *= dodalem[pos];

            dodaj(pos, zeit, -odejme);
            dodajSuf(pos, -odejme);

            dodaj(poprz, zeit, dodam);
            dodajSuf(poprz, dodam);

            dodaneAktualnie.erase(pos);
        } else {
            int pos1 = pozycja[A[i]];
            int pos2 = pozycja[B[i]];

            if (C[i] <= 0) {
                printf("%d\n", A[i]);
                continue;
            }

            long long v = C[i] - czytajPref(pos1 - 1);

            int pocz = pos1 - 1, kon = pos2 + 1;
            while (pocz != kon - 1) {
                int sr = (kon + pocz) / 2;
                wynikCzytania = LLONG_MAX;
                czytaj(pos1, sr);
                if (wynikCzytania + v <= 0) {
                    kon = sr;
                } else {
                    pocz = sr;
                }
            }

            if (kon == pos2 + 1) {
                printf("-1\n");
                continue;
            }

            int moment = realne[kon];
            v += czytajPref(kon - 1);
            double wybuch = moment;
            if (dodalem[kon] != 0)
                wybuch -= v / (double) dodalem[kon];
            if (wybuch <= B[i])
                printf("%lf\n", wybuch);
            else
                printf("-1\n");
        }
    }
    return 0;
}