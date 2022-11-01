#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
long long w[2000000];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        w[x]++;
    }
    int res = 0;
    FO(i,0,2000000-1) {
        long long a = w[i]/2;
        if (w[i]&1) res++;
        w[i+1] += a;
    }
    printf("%d\n", res);
}