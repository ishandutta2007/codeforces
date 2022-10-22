#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b) {
    return a>b;
}

long long int emotes[202020];

int main() {
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    for (int i=0; i<n; i++) {
        scanf("%lld", &emotes[i]);
    }

    sort(emotes, emotes+n, cmp);

    long long int maxHappy = 0;
    if (emotes[0] == emotes[1]) {
        maxHappy = (long long int) emotes[0] * m;
    }
    else {
        int a = m/(k+1);
        int b = m%(k+1);
        maxHappy = (long long int) emotes[0] * ((long long int) a*k+b) + (long long int) emotes[1] * a;
    }

    printf("%lld", maxHappy);
}