#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f[100005];
int t[100005];
int n;

int main() {
    scanf("%d", &n);
    f[0] = 0;
    t[0] = -1000000;
    FO(i,1,n+1) {
        scanf("%d", &t[i]);
        f[i] = f[i-1] + 20;

        int j = lower_bound(t, t+i, t[i]-89)-t-1;
        f[i] = min(f[i], f[j] + 50);

        j = lower_bound(t, t+i, t[i]-1439)-t-1;
        f[i] = min(f[i], f[j] + 120);

        printf("%d\n", f[i]-f[i-1]);
    }
}