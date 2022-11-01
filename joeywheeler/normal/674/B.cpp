#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
int v[1005];
int u[1005];
int a, b, c, d;
int p[1005];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (n == 4) {
        printf("-1\n");
        return 0;
    }
    if (k < n+1) {
        printf("-1\n");
        return 0;
    }
    FO(i,0,n) {
        v[i] = i;
        u[i] = i;
    }
    swap(u[0],u[1]);
    swap(u[n-1],u[n-2]);
    set<int> s;
    FO(i,1,n+1) s.insert(i);
    p[0] = a; s.erase(a);
    p[1] = c; s.erase(c);
    p[n-2] = d; s.erase(d);
    p[n-1] = b; s.erase(b);
    FO(i,2,n-2) p[i] = *s.begin(), s.erase(p[i]);
    FO(i,0,n) printf("%d ", p[v[i]]);
    printf("\n");
    FO(i,0,n) printf("%d ", p[u[i]]);
    printf("\n");
}