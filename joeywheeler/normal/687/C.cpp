#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
bitset<505> c[505];

int main() {
    scanf("%d %d", &n, &k);
    c[0].set(0);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        for (int i = 504; i >= 0; i--) {
            if (i >= x) c[i] |= c[i-x] | (c[i]<<x);
            else c[i] |= c[i]<<x;
        }
    }
    vector<int> v;
    FO(i,0,k+1) if (c[i].test(k-i)) v.push_back(i);
    printf("%d\n", sz(v));
    for (int x : v) printf("%d ", x);
    printf("\n");
}