#include <cstdio>
#include <set>

int tab[100007];
int left[100007];
int right[100007];

std::set<int> byl;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
    }
    for (int i = 0; i < N; i++) {
        if (byl.count(tab[i]) == 0) {
            byl.insert(tab[i]);
            left[i] = tab[i];
        } else {
            left[i] = -1;
        }
    }
    byl.clear();
    for (int i = N - 1; i >= 0; i--) {
        if (byl.count(tab[i]) == 0) {
            byl.insert(tab[i]);
            right[i] = tab[i];
        } else {
            right[i] = -2;
        }
    }
    int dod = (int) byl.size();
    long long wyn = 0;
    for (int i = 0; i < N; i++) {
        if (left[i] == right[i])
            dod--;
        if (left[i] == -1) {
            if (right[i] != -2)
                dod--;
            continue;
        }
        wyn += dod;
    }
    printf("%lld\n", wyn);
    return 0;
}