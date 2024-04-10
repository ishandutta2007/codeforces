#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[100005];
int r = 0;
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        l[x] = 1 + l[x-1];
        r = max(r,l[x]);
    }
    printf("%d\n", n-r);
}