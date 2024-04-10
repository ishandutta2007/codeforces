#include <cstdio>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

set<tuple<int, int, int, int>> seen;
bool okg, okh, okr, oks;
char str[10001];

void solve(int n, int g, int h, int r, int s) {
    if (!seen.emplace(g, h, r, s).second)
        return;

    int i = g + h + r + s;
    if (i == n) {
        int mini = min(min(g, h), min(r, s));
        if (g == mini) okg = true;
        if (h == mini) okh = true;
        if (r == mini) okr = true;
        if (s == mini) oks = true;
        return;
    }
    switch (str[i]) {
        case 'G':
            solve(n, g + 1, h, r, s);
            break;
        case 'H':
            solve(n, g, h + 1, r, s);
            break;
        case 'R':
            solve(n, g, h, r + 1, s);
            break;
        case 'S':
            solve(n, g, h, r, s + 1);
            break;
        case '?': {
            int mini = min(min(g, h), min(r, s));
            if (g == mini) solve(n, g + 1, h, r, s);
            if (h == mini) solve(n, g, h + 1, r, s);
            if (r == mini) solve(n, g, h, r + 1, s);
            if (s == mini) solve(n, g, h, r, s + 1);
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d%s", &n, str);
    solve(n, 0, 0, 0, 0);
    if (okg) puts("Gryffindor");
    if (okh) puts("Hufflepuff");
    if (okr) puts("Ravenclaw");
    if (oks) puts("Slytherin");
}