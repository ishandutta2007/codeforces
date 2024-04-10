#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
using namespace std;

char ma[5001][5001];

int ar[5000];
int n;

struct TComp {
    int p;
    TComp(int P) : p(P) {}
    inline bool operator()(int x) {
        return (ma[p][x]=='0');
    }
};

bool findTriple(int l, int r) {
    if (r - l < 3) return false;
    int f = ar[l];
    int c = partition(ar + l+1, ar + r, TComp(f)) - (ar + l + 1);
    if (c != 0) swap(ar[l], ar[l+c]);
    /*for (int i = 0; i < c-1; i++) {
        if (ar[i + l] == f) swap(ar[i+l], ar[i+c-1]);
    }*/
    ++c;
    for (int i = 0; i < c-1; i++) {
        for (int j = c; j < r - l; j++) {
            if (ma[ar[j+l]][ar[i+l]]=='1') {
                printf("%d %d %d\n", f + 1, ar[j+l] + 1, ar[i+l] + 1);
                return true;
            }
        }
    }
    if (findTriple(l, l+c-1)) return true;
    return findTriple(l+c, r);
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ma[i]);
        if (ma[i][i] != '0') return 1;
        ar[i] = i;
    }
    if (!findTriple(0, n))
        printf("-1\n");
    return 0;
}