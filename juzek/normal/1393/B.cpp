#include <bits/stdc++.h>

using namespace std;

int ile[1000007];
int licz[1000007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        ile[a]++;
        licz[ile[a]]++;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        char c;
        scanf(" %c", &c);
        int a;
        scanf("%d", &a);
        if (c == '-') {
            licz[ile[a]]--;
            ile[a]--;
        } else {
            ile[a]++;
            licz[ile[a]]++;
        }
        if (licz[8] >= 1)
            printf("YES\n");
        else if (licz[6] >= 1 && licz[2] >= 2)
            printf("YES\n");
        else if (licz[4] >= 2)
            printf("YES\n");
        else if (licz[4] >= 1 && licz[2] >= 3)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}