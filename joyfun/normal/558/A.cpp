#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Tree {
    int v, a;
    void read() {
        scanf("%d%d", &v, &a);
    }
} L[105], R[105];

int ln, rn;
int n;

bool cmp1(Tree a, Tree b) {
    return a.v < b.v;
}

bool cmp2(Tree a, Tree b) {
    return a.v > b.v;
}

int main() {
    scanf("%d", &n);
    Tree sb;
    while (n--){
        sb.read();
        if (sb.v < 0) L[ln++] = sb;
        else R[rn++] = sb;
    }
    sort(L, L + ln, cmp2);
    sort(R, R + rn, cmp1);
    int ans = 0;
    if (ln > rn) {
        for (int i = 0; i < rn; i++) ans += R[i].a;
        for (int i = 0; i < rn + 1; i++) ans += L[i].a;
    } else if (ln == rn) {
        for (int i = 0; i < rn; i++) ans += R[i].a;
        for (int i = 0; i < rn; i++) ans += L[i].a;
    } else {
        for (int i = 0; i < ln + 1; i++) ans += R[i].a;
        for (int i = 0; i < ln; i++) ans += L[i].a;
    }
    printf("%d\n", ans);
    return 0;
}