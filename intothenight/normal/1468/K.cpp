#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

char s[MAXN];
int n, dx[256], dy[256];

bool check(int objX, int objY) {
    int curX = 0, curY = 0;
    for(int i = 0; i < n; ++i) {
        int newX = curX + dx[s[i]], newY = curY + dy[s[i]];
        if (newX != objX || newY != objY) {
            curX = newX;
            curY = newY;
        }
    }
    return (curX == 0 && curY == 0);
}

int main() {
    dx['D'] = 0; dy['D'] = -1;
    dx['U'] = 0; dy['U'] = 1;
    dx['L'] = -1; dy['L'] = 0;
    dx['R'] = 1; dy['R'] = 0;

    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        scanf("%s", s);
        n = strlen(s);

        int curX = 0, curY = 0;
        int ansX = 0, ansY = 0;
        for(int i = 0; i < n; ++i) {
            int newX = curX + dx[s[i]], newY = curY + dy[s[i]];
            if (check(newX, newY)) {
                ansX = newX;
                ansY = newY;
                break;
            }
            curX = newX; curY = newY;
        }

        printf("%d %d\n", ansX, ansY);
    }

    return 0;
}