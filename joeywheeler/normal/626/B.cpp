#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int c[256];
bool p[256];

void go(int r, int g, int b) {
    if (r+g+b == 1) {
        if (r==1) p['R'] = true;
        if (g==1) p['G'] = true;
        if (b==1) p['B'] = true;
    } else {
        if (r >= 2) go(r-1,g,b);
        if (g >= 2) go(r,g-1,b);
        if (b >= 2) go(r,g,b-1);
        if (r&&g) go(r-1,g-1,b+1);
        if (r&&b) go(r-1,g+1,b-1);
        if (g&&b) go(r+1,g-1,b-1);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        char t; scanf(" %c", &t);
        c[t]++;
    }
    int r = c['R'], g = c['G'], b = c['B'];
    r = min(r,2);
    g = min(g,2);
    b = min(b,2);

    go(r,g,b);
    FO(i,0,256) if (p[i]) printf("%c", i);
    printf("\n");
}