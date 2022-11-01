#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a[2005], d, n;
vector<int> u[2005];

int root=0;
long long f(int i, int p) {
    long long res = 1;
    for (auto c : u[i]) if (c != p && a[root] <= a[c] && a[c] <= a[root]+d) {
        if (a[c] == a[root] && c < root) continue;
        res *= f(c, i) + 1;
        res %= 1000000007;
    }
    return res;
}

int main() {
    scanf("%d %d", &d, &n);
    FO(i,0,n) scanf("%d",a+i+1);
    FO(i,0,n-1) {
        int x,y; scanf("%d%d", &x, &y);
        u[x].push_back(y); u[y].push_back(x);
    }
    long long r=0;
    FO(i,1,n+1) root=i, r += f(i,0);
    r %= 1000000007;
    printf("%lld\n", r);
}