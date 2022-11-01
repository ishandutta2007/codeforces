#include <cstdio>
#include <map>

int tab[1000007];
int pref[1000007];

std::map<int, int> byloParz, byloNieparz;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] ^ tab[i];
    long long wyn = 0;
//    for (int i = 1; i <= N; i++) {
//        printf("%d ", pref[i]);
//    }
    byloParz[0]++;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            wyn += byloParz[pref[i]];
            byloParz[pref[i]]++;
        }
        else {
            wyn += byloNieparz[pref[i]];
            byloNieparz[pref[i]]++;
        }
    }
    printf("%lld", wyn);
    return 0;
}