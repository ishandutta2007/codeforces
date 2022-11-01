#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

int tab[100007];
int ter[100007];
int dpL[100007], dpR[100007];
long long ileL[100007], ileR[100007];
std::vector<int> ktore[100007];
int N;

const int mod = 1000696969;

void wrzuc(long long* drzewo, int a, long long war, int s) {
    while (a <= s) {
        drzewo[a] += war;
        drzewo[a] %= mod;
        a += a & -a;
    }
}

long long policz(long long* drzewo, int a) {
    long long ret = 0;
    while (a > 0) {
        ret += drzewo[a];
        ret %= mod;
        a -= a & -a;
    }
    return ret;
}

int przelicz(int* dp, long long* ile) {
    int maxi = 0;
    ktore[0].push_back(0);
    for (int i = 1; i <= N; i++) {
        int pos = int(std::lower_bound(ter, ter + maxi + 1, tab[i]) - ter);
        ter[pos] = tab[i];
        dp[i] = pos;
        ktore[pos].push_back(tab[i]);
        if (pos > maxi)
            maxi = pos;
    }
    std::vector<long long*> drzewka;
    std::vector<unsigned long> rozm;
    for (int i = 0; i <= maxi; i++) {
        std::sort(ktore[i].begin(), ktore[i].end());
        rozm.push_back((ktore[i].size() + 5));
        drzewka.push_back(new long long[rozm.back()]);
        memset(drzewka.back(), 0, sizeof(long long) * rozm.back());
    }
    wrzuc(drzewka[0], 1, 1, 1);
    for (int i = 1; i <= N; i++) {
        int pos = int(std::lower_bound(ktore[dp[i] - 1].begin(), ktore[dp[i] - 1].end(), tab[i]) - ktore[dp[i] - 1].begin());
        ile[i] = policz(drzewka[dp[i] - 1], pos);
        int mojPos = int(std::lower_bound(ktore[dp[i]].begin(), ktore[dp[i]].end(), tab[i]) - ktore[dp[i]].begin()) + 1;
        wrzuc(drzewka[dp[i]], mojPos, ile[i], (int) rozm[dp[i]] - 1);
    }
    for (int i = 0; i <= maxi; i++)
        ktore[i].clear();
    return maxi;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    int maxi = przelicz(dpL, ileL);
    for (int i = 1; i <= N; i++)
        tab[i] = 1000000 - tab[i];
    for (int i = 1; i <= N / 2; i++)
        std::swap(tab[N - i + 1], tab[i]);
    przelicz(dpR, ileR);
    for (int i = 1; i <= N / 2; i++) {
        std::swap(dpR[N - i + 1], dpR[i]);
        std::swap(ileR[N - i + 1], ileR[i]);
    }
    long long sposoby = 0;
    for (int i = 1; i <= N; i++)
        if (dpL[i] == maxi)
            sposoby += ileL[i];
    sposoby %= mod;
    for (int i = 1; i <= N; i++) {
        if (dpL[i] + dpR[i] != maxi + 1)
            printf("1");
        else if ((ileL[i] * ileR[i]) % mod == sposoby)
            printf("3");
        else
            printf("2");
    }
    return 0;
}