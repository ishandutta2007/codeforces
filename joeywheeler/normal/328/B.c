// write in C...
#include <stdio.h>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

char t[10];
char s[300];

int num_need[256];
int num_have[256];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int main() {
    int i;

    scanf("%s %s", t, s);
    for (i = 0; t[i]; i++) num_need[t[i]]++;
    for (i = 0; s[i]; i++) num_have[s[i]]++;

    num_need['6'] += num_need['9'];
    num_need['9'] = 0;
    num_need['2'] += num_need['5'];
    num_need['5'] = 0;

    num_have['6'] += num_have['9'];
    num_have['9'] = 0;
    num_have['2'] += num_have['5'];
    num_have['5'] = 0;

    int res = 2000000000;

    for (i = 0; i < 256; i++)
        if (num_need[i])
            res = min(res, num_have[i] / num_need[i]);

    printf("%d\n", res);

    return 0;
}