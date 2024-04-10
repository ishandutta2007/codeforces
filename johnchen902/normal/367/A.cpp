#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100001];
int cx[100001], cy[100001], cz[100001];

bool solve(int l, int r) {
    if (r - l <= 2)
        return true;
    int x = cx[r] - cx[l];
    int y = cy[r] - cy[l];
    int z = cz[r] - cz[l];
    return max(x, max(y, z)) - min(x, min(y, z)) <= 1;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        cx[i + 1] = cx[i] + (s[i] == 'x');
        cy[i + 1] = cy[i] + (s[i] == 'y');
        cz[i + 1] = cz[i] + (s[i] == 'z');
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        puts(solve(l, r) ? "YES" : "NO");
    }
}