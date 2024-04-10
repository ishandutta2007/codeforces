#include <cstdio>
#include <algorithm>

struct V;
const int Z = 1024 * 1024 * 1024;
const int z = 1024 * 128;
int N, K;

int drzewo[z * 2 + 7];
V *super_drzewo;
int wynik;

int czytaj(int a, int b) {
    a += z - 1, b += z + 1;
    int ret = 1337133713;
    while (a != b - 1) {
        if (a % 2 == 0)
            ret = std::min(ret, drzewo[a + 1]);
        if (b % 2 == 1)
            ret = std::min(ret, drzewo[b - 1]);
        a /= 2, b /= 2;
    }
    return ret;
}

int czytajMin(int lewy, int prawy) {
    if (prawy - lewy + 1 >= N)
        return czytaj(0, N - 1);
    if (lewy / N == prawy / N)
        return czytaj(lewy % N, prawy % N);
    return std::min(czytaj(lewy % N, N - 1), czytaj(0, prawy % N));
}

struct V {
    V *lewy = nullptr, *prawy = nullptr;
    int mini = -1, pomoc = -1;

    V(int mini) : mini(mini) {

    }

    void spychaj(int l, int r) {
        int sr = (l + r) / 2;
        if (!lewy)
            lewy = new V(czytajMin(l, sr));
        if (!prawy)
            prawy = new V(czytajMin(sr + 1, r));
        if (pomoc != -1) {
            lewy->mini = prawy->mini = lewy->pomoc = prawy->pomoc = pomoc;
            pomoc = -1;
        }
    }

    void aktualizuj() {
        mini = std::min(lewy->mini, prawy->mini);
    }
};

void ustaw(int ll, int rr, int war, V *v = super_drzewo, int l = 0, int r = Z - 1) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        v->pomoc = v->mini = war;
        return;
    }
    v->spychaj(l, r);
    int sr = (l + r) / 2;
    ustaw(ll, rr, war, v->lewy, l, sr);
    ustaw(ll, rr, war, v->prawy, sr + 1, r);
    v->aktualizuj();
}

void czytajWynik(int ll, int rr, V *v = super_drzewo, int l = 0, int r = Z - 1) {
    if (r < ll || rr < l)
        return;
    if (ll <= l && r <= rr) {
        wynik = std::min(wynik, v->mini);
        return;
    }
    v->spychaj(l, r);
    int sr = (l + r) / 2;
    czytajWynik(ll, rr, v->lewy, l, sr);
    czytajWynik(ll, rr, v->prawy, sr + 1, r);
    v->aktualizuj();
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &drzewo[i + z]);
    for (int i = z - 1; i >= 0; i--)
        drzewo[i] = std::min(drzewo[i * 2], drzewo[i * 2 + 1]);
    super_drzewo = new V(czytaj(0, N - 1));
    int Q;
    scanf("%d", &Q);
    int t;
    int a, b, c;
    while (Q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            ustaw(a, b, c);
        } else {
            scanf("%d%d", &a, &b);
            wynik = 1337133713;
            a--, b--;
            czytajWynik(a, b);
            printf("%d\n", wynik);
        }
    }
    return 0;
}