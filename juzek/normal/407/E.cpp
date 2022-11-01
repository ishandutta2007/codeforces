#include <cstdio>
#include <map>
#include <vector>

const int MAXN = 200007;

int tab[MAXN];
int dokad[MAXN];

std::map<int, int> jest;
int K, D;

const int Z = 1024 * 256;
int drzewo[Z * 2 + 7];
int sp[Z * 2 + 7];

void spychaj(int v) {
    if (sp[v] != 0) {
        sp[v * 2] += sp[v];
        sp[v * 2 + 1] += sp[v];
        drzewo[v * 2] += sp[v];
        drzewo[v * 2 + 1] += sp[v];
        sp[v] = 0;
    }
}

void wrzuc(int war, int ll, int rr, int v = 1, int l = 1, int r = Z) {
    if (r < ll || l > rr)
        return;
    if (ll <= l && r <= rr) {
        sp[v] += war;
        drzewo[v] += war;
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    wrzuc(war, ll, rr, v * 2, l, sr);
    wrzuc(war, ll, rr, v * 2 + 1, sr + 1, r);
    drzewo[v] = std::min(drzewo[v * 2], drzewo[v * 2 + 1]);
}

int naj = -1;

void szukaj(int st, int ll, int rr, int v = 1, int l = 1, int r = Z) {
    if (r < ll || l > rr || r < naj || drzewo[v] > st)
        return;
    if (ll <= l && r <= rr && l == r) {
        naj = std::max(naj, r);
        return;
    }
    spychaj(v);
    int sr = (l + r) / 2;
    szukaj(st, ll, rr, v * 2 + 1, sr + 1, r);
    szukaj(st, ll, rr, v * 2, l, sr);
}

std::pair<int, int> wynik = {0, 0};

void super_fft(int N) {
    int las = -1;
    int ile = 0;
    std::pair<int, int> wyn = {0, 0};
    for (int i = 1; i <= N; i++) {
        if (tab[i] != las) {
            ile = 0;
            las = tab[i];
        }
        ile++;
        wyn = std::max(wyn, {ile, -i});
    }
    printf("%d %d", -wyn.second - wyn.first + 1, -wyn.second);
}

int main() {
    int N;
    scanf("%d%d%d", &N, &K, &D);
    for (int i = 1; i <= N; i++)
        drzewo[i + Z - 1] = -i;
    for (int i = Z - 1; i >= 1; i--)
        drzewo[i] = std::min(drzewo[i * 2], drzewo[i * 2 + 1]);
    int xd = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        xd = std::min(xd, tab[i]);
    }
    for (int i = 1; i <= N; i++)
        tab[i] -= xd;

    if (D == 0) {
        super_fft(N);
        return 0;
    }

    int ter = 0;
    for (int i = 1; i <= N; i++) {
        int reszta = tab[i] % D;
        while (ter + 1 <= N && tab[ter + 1] % D == reszta && jest[tab[ter + 1]] == 0) {
            jest[tab[++ter]]++;
        }
        jest[tab[i]]--;
        tab[i] -= reszta;
        tab[i] /= D;
        dokad[i] = ter;
//        printf("%d ", tab[i]);
    }
//    printf("\n");
//    for (int i = 1; i <= N; i++)
//        printf("%d ", dokad[i]);
//    printf("\n");
    std::vector<std::pair<int, int>> maxy;
    std::vector<std::pair<int, int>> miny;
    for (int i = N; i >= 1; i--) {
        int las = i;
        while (!maxy.empty() && maxy.back().first <= tab[i]) {
            wrzuc(tab[i] - maxy.back().first, las + 1, maxy.back().second);
            las = maxy.back().second;
            maxy.pop_back();
        }
        maxy.emplace_back(tab[i], las);

        las = i;
        while (!miny.empty() && miny.back().first >= tab[i]) {
            wrzuc(miny.back().first - tab[i], las + 1, miny.back().second);
            las = miny.back().second;
            miny.pop_back();
        }
        miny.emplace_back(tab[i], las);

//        for (int w = 1; w <= N; w++) {
//            szukaj(1337133713, w, w);
//            printf("%d ", drzewo[w + Z - 1]);
//        }
//        printf("\n");

        naj = -1;
        szukaj(K - i, i, dokad[i]);
//        printf("%d: %d\n", i, naj);
        wynik = std::max(wynik, {naj - i + 1, -i});
    }
    printf("%d %d", -wynik.second, -wynik.second + wynik.first - 1);
    return 0;
}