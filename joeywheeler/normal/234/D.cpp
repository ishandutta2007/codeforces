#include <cstdio>
#include <algorithm>

#define MAX_N 210

using namespace std;

int n, k;
int m;

bool fav[MAX_N];
char name[100];
int min_fav[MAX_N];
int max_fav[MAX_N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        fav[x] = true;
    }

    scanf("%d", &n);

    int max_min = 0, max_max = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %s ", name);

        int d;
        scanf("%d", &d);

        int def_fav = 0, def_non = 0, who_knows = 0;
        for (int j = 0; j < d; j++) {
            int x;
            scanf("%d", &x);
            if (!x) who_knows++;
            else if (fav[x]) def_fav++;
            else if (!fav[x]) def_non++;
        }
        int fav_rem = k-def_fav;
        int non_rem = m-k-def_non;
        min_fav[i] = def_fav + max(who_knows-non_rem,0);
        max_fav[i] = def_fav + min(fav_rem,who_knows);
    }

    for (int i = 0; i < n; i++) {
        bool can_fav = true, can_not = false;
        for (int j = 0; j < n; j++) if (min_fav[j] > max_fav[i]) can_fav = false;
        for (int j = 0; j < n; j++) if (j != i && min_fav[i] < max_fav[j]) can_not = true;
        if (can_fav && can_not) printf("2\n");
        else if(can_fav) printf("0\n");
        else printf("1\n");
    }
}