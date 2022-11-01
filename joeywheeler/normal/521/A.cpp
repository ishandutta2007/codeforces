#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char buf[100010];
int t[1000];

int main() {
    int n; scanf(" %d", &n);
    scanf(" %s", buf);
    int l = strlen(buf);
    FO(i,0,l) t[int(buf[i])]++;
    int mx = 0;
    FO(i,0,1000) mx = max(mx, t[i]);
    int c = 0;
    FO(i,0,1000) if (t[i] == mx) c++;
    long long res = 1;
    FO(i,0,l) {
        res *= c;
        res %= 1000000007;
    }
    printf("%d\n", int(res));
}