#include <cstdio>

#define MAX_N 110

using namespace std;

int n;
char buff[MAX_N];

void match(int a, int b) {
    if (buff[a] == 'R' && buff[b] == 'L') {
        printf("%d %d\n", b+1, a+1);
    } else {
        printf("%d %d\n", a+1, b+1);
    }
    buff[a] = buff[b] = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(" %c ", &buff[i]);
    for (int i = 0; i < n; i += 3) {
        if (i+2 < n) {
            match(i, i+2);
        }
    }
    if (buff[n-1] != 0) {
        match(1, n-1);
    }
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (buff[i] != 0) {
            if (prev != -1) {
                match(prev, i);
                prev = -1;
            } else {
                prev = i;
            }
        }
    }
}