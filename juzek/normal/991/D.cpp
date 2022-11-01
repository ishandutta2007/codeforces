#include <cstdio>
#include <string>
#include <iostream>

int dp_gora[107];
int dp_dol[107];
int dp_oba[107];
int dp_zaden[107];

char gora[107], dol[107];

void wypisz(int N, int* tab) {
    for (int i = 0; i <= N; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main() {
    scanf(" %s", gora + 1);
    scanf(" %s", dol + 1);
    int N = 0;
    while (gora[N + 1] != 0)
        N++;
//    printf("%d\n", N);
    for (int i = 2; i <= N; i++) {
        dp_zaden[i] = dp_zaden[i - 1];
        // X.
        // XX
        if (gora[i - 1] == '0' && dol[i - 1] == '0' && dol[i] == '0') {
            if (gora[i] == '0')
                dp_gora[i] = dp_oba[i - 1] + 1;
            else
                dp_zaden[i] = std::max(dp_zaden[i], dp_oba[i - 1] + 1);
        }
        // XX
        // X.
        if (gora[i - 1] == '0' && dol[i - 1] == '0' && gora[i] == '0') {
            if (dol[i] == '0')
                dp_dol[i] = dp_oba[i - 1] + 1;
            else
                dp_zaden[i] = std::max(dp_zaden[i], dp_oba[i - 1] + 1);
        }
        // XX
        // .X
        if (gora[i - 1] == '0' && dol[i] == '0' && gora[i] == '0')
            dp_zaden[i] = std::max(dp_zaden[i], dp_gora[i - 1] + 1);
        // .X
        // XX
        if (dol[i - 1] == '0' && dol[i] == '0' && gora[i] == '0')
            dp_zaden[i] = std::max(dp_dol[i - 1] + 1, dp_zaden[i]);
        dp_zaden[i] = std::max(dp_zaden[i], std::max(dp_gora[i], dp_dol[i]));
        int maxi = std::max(std::max(dp_oba[i - 1], dp_gora[i - 1]), std::max(dp_dol[i - 1], dp_zaden[i - 1]));
        if (dol[i] == '0' && gora[i] == '0')
            dp_oba[i] = std::max(dp_oba[i], maxi);
        if (dol[i] == '0')
            dp_dol[i] = std::max(dp_dol[i], maxi);
        if (gora[i] == '0')
            dp_gora[i] = std::max(dp_gora[i], maxi);
        dp_zaden[i] = std::max(dp_zaden[i], maxi);
    }
    int maxi = 0;
    for (int i = 0; i <= N; i++) {
        maxi = std::max(maxi, dp_gora[i]);
        maxi = std::max(maxi, dp_dol[i]);
        maxi = std::max(maxi, dp_oba[i]);
        maxi = std::max(maxi, dp_zaden[i]);
    }
    printf("%d", maxi);
    return 0;
}