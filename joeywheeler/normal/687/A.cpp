#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> u[100005];
bool f;
int d[100005];

void go(int i, int dd) {
    if (d[i]) {
        f |= dd != d[i];
        return;
    }
    d[i] = dd;
    for (int j : u[i]) go(j, 3-dd);
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;
        u[x].push_back(y);
        u[y].push_back(x);
    }
    FO(i,0,n) if (!d[i]) go(i,1);
    if (f) {
        printf("-1\n");
        return 0;
    }
    int r = 0;
    FO(i,0,n) r += d[i] == 1;
    printf("%d\n", r);
    FO(i,0,n) if (d[i] == 1) printf("%d ", i+1);
    printf("\n");
    r = 0;
    FO(i,0,n) r += d[i] == 2;
    printf("%d\n", r);
    FO(i,0,n) if (d[i] == 2) printf("%d ", i+1);
    printf("\n");
}