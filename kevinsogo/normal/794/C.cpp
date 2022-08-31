#include <bits/stdc++.h>
using namespace std;

#define N 1111111

void minim(int n, char* s, char* t, char* u);
void maxim(int n, char* s, char* t, char* u) {
    if (n == 0) return;
    if (*s < *t) {
        *(u++) = *(s++);
        minim(n - 1, t, s, u);
    } else {
        if (n % 2) *(u++) = *(s++), n--;
        for (; n; n -= 2) {
            *(u++) = *(t++);
            *(u++) = *(s++);
        }
    }
}
void minim(int n, char* s, char* t, char* u) {
    if (n == 0) return;
    if (*s > *t) {
        *(u++) = *(s++);
        maxim(n - 1, t, s, u);
    } else {
        if (n % 2) *(u++) = *(s++), n--;
        for (; n; n -= 2) {
            *(u++) = *(t++);
            *(u++) = *(s++);
        }
    }
}

char s[N];
char t[N];
char u[N];
int main() {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    sort(s, s + n);
    sort(t, t + n);
    reverse(t, t + n);
    maxim(n, s, t, u);
    u[n] = 0;
    printf("%s\n", u);
}