#include <cstdio>
#include <algorithm>

int tab[1000007];
int pref[1000007];
int maxi[1000007];
int bylo[1000007];
int ktora[1000007];

int main() {
    int N, c;
    scanf("%d%d", &N, &c);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        maxi[tab[i]] = -1337133713;
        pref[i] = pref[i - 1];
        if (tab[i] == c)
            pref[i]++;
    }
    for (int i = 1; i <= N; i++) {
        bylo[tab[i]]++;
        ktora[i] = bylo[tab[i]];
    }
    int suma = pref[N];
    int wyn = 0;
    for (int i = 1; i <= N; i++) {
        maxi[tab[i]] = std::max(maxi[tab[i]], pref[i - 1] - ktora[i] + 1);
        wyn = std::max(wyn, maxi[tab[i]] + suma - pref[i] + ktora[i]);
    }
    printf("%d", wyn);
    return 0;
}