#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char g[1005][1005];
char a[1005][1005];
int l[1005*1005];
int s[1005*1005];
int h, w;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

int gl(int i) {
    if (l[i] == i) return i;
    else return l[i] = gl(l[i]);
}

void u(int i, int j) {
    i = gl(i); j = gl(j);
    if (i-j) {
        s[i] += s[j];
        if (s[i] >= 10) s[i] -= 10;
        l[j] = i;
    }
}

int main() {
    scanf("%d %d", &h, &w);
    FO(y,0,h) {
        scanf(" %s", g[y]);
        FO(x,0,w) {
            l[y*w+x] = y*w+x;
            s[y*w+x] = 1;
        }
    }
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') {
        FO(i,0,4) {
            int ny = y+dy[i], nx = x+dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') {
                u(y*w+x, ny*w+nx);
            }
        }
    }
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '*') {
        set<int> seen;
        FO(i,0,4) {
            int ny = y+dy[i], nx = x+dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') {
                seen.insert(gl(ny*w+nx));
            }
        }
        int res = 1;
        for (int X : seen) {
            res += s[X];
            if (res >= 10) res -= 10;
        }
        a[y][x] = res + '0';
    } else {
        a[y][x] = '.';
    }
    FO(y,0,h) printf("%s\n", a[y]);
}