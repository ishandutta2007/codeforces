#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e5 * 2 + 5;

int n, k;
int t[MAXN];
int ile[200];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    for(int i = 0; i < n; i++){
        int wiel;
        wiel = t[i]/k;
        wiel *= k;

        if(wiel - t[i] < 0) wiel += k;

        ile[wiel - t[i]]++;
    } 

    /*
    for(int i = 0; i < 4; i++)
        printf("%d ", ile[i]);
    */

    int pairs = 0;
    pairs += ile[0] / 2;
    for(int i = 1; i < k/2+1 and i != k - i; i++){
        int p = min(ile[i], ile[k - i]);
        pairs += p;
    }
    if(k % 2 == 0) pairs += ile[k/2] / 2;

    printf("%d\n", pairs*2);

    return 0;
}