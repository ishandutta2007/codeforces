#include <bits/stdc++.h>

#define fir first
#define sec second

using Pair = std::pair<int, int>;

const int N = 205, L = 1 << 20;

char qq[L];
char s[N][N];

int brred, brstup;
int brc = 1;
int indeg[N][N];
int cik[N][N];
int imacik[N * N][10];
int pr[10], ps[10];
int bio[N][N];
int dokle[N][N];
int imaq[L][10];

Pair kamo[N][N];

std::vector<Pair> R[N][N];

int Vani(int red, int stup) { return red < 0 || red >= brred || stup < 0 || stup >= brstup; }

void Osisaj() {
    std::queue<Pair> Q;
    for (int i = 0; i < brred; ++i) {
        for (int j = 0; j < brstup; ++j) {
            if (!indeg[i][j]) Q.push(Pair(i, j));
        }
    }
    for (; !Q.empty();) {
        Pair tmp = Q.front();
        bio[tmp.fir][tmp.sec] = 1;
        Q.pop();
        Pair nn = kamo[tmp.fir][tmp.sec];
        --indeg[nn.fir][nn.sec];
        if (!indeg[nn.fir][nn.sec]) Q.push(nn);
    }
    for (int i = 0; i < brred; ++i) {
        for (int j = 0; j < brstup; ++j) {
            if (!bio[i][j]) {
                int sz = 0;
                for (Pair tmp = Pair(i, j); tmp != Pair(i, j) || !sz; sz++, tmp = kamo[tmp.fir][tmp.sec]) {
                    bio[tmp.fir][tmp.sec] = 1;
                    cik[tmp.fir][tmp.sec] = brc;
                    imacik[brc][s[tmp.fir][tmp.sec] - '0'] = 1;
                }
                ++brc;
            }
        }
    }
}

int Rijesi() {
    std::queue<Pair> Q;
    memset(dokle, 0, sizeof dokle);
    int len = (int)strlen(qq);
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j < 10; ++j) imaq[i][j] = 0;
    }
    for (int i = len - 1; i >= 0; i--) {
        imaq[i][qq[i] - '0'] = 1;
        for (int j = 0; j < 10; ++j) imaq[i][j] |= imaq[i + 1][j];
    }
    for (int i = 0; i < brred; ++i)
        for (int j = 0; j < brstup; ++j) {
            indeg[i][j] = (int)R[i][j].size();
            if (!indeg[i][j]) Q.push(Pair(i, j));
        }
    for (; !Q.empty();) {
        Pair tmp = Q.front();
        Q.pop();
        int nd = dokle[tmp.fir][tmp.sec];
        if (s[tmp.fir][tmp.sec] == qq[nd]) nd++;
        if (nd == len) return 1;
        Pair nn = kamo[tmp.fir][tmp.sec];
        dokle[nn.fir][nn.sec] = std::max(dokle[nn.fir][nn.sec], nd);
        --indeg[nn.fir][nn.sec];
        if (!indeg[nn.fir][nn.sec]) Q.push(nn);
    }
    for (int i = 0; i < brred; ++i) {
        for (int j = 0; j < brstup; ++j) {
            if (cik[i][j]) {
                int da = 1;
                int indc = cik[i][j];
                for (int k = 0; k < 10; ++k) {
                    if (!imacik[indc][k] && imaq[dokle[i][j]][k]) da = 0;
                }
                if (da) return 1;
            }
        }
    }
    return 0;
}

int main() {
    int brq;
    scanf("%d %d %d", &brred, &brstup, &brq);
    for (int i = 0; i < brred; ++i) scanf("%s", s[i]);
    for (int i = 0; i < 10; ++i) scanf("%d%d", &pr[i], &ps[i]);
    for (int i = 0; i < brred; ++i) {
        for (int j = 0; j < brstup; ++j) {
            int nr = i + pr[s[i][j] - '0'];
            int ns = j + ps[s[i][j] - '0'];
            if (Vani(nr, ns)) {
                kamo[i][j] = Pair(i, j);
            } else {
                kamo[i][j] = Pair(nr, ns);
            }
            indeg[kamo[i][j].fir][kamo[i][j].sec]++;
            R[kamo[i][j].fir][kamo[i][j].sec].push_back(Pair(i, j));
        }
    }
    Osisaj();
    for (int i = 0; i < brq; ++i) {
        scanf("%s", qq);
        printf("%s\n", Rijesi() ? "YES" : "NO");
    }
    return 0;
}