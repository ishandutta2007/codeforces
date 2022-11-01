#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define mt make_tuple

using namespace std;

int n;
char buf[5005];
int f[26][5005][26];

int main() {
    scanf(" %s", buf);
    n = strlen(buf);
    fo(i,0,n) {
        int t = i;
        fo(j,0,n) {
            f[buf[i]-'a'][j][buf[t]-'a']++;
            t++;
            if (t == n) t = 0;
        }
    }
    int res = 0;
    fo(i,0,26) {
        int mx = 0;
        fo(j,0,n) {
            int v = 0;
            fo(k,0,26) if (f[i][j][k] == 1) v++;
            mx = max(mx, v);
        }
        res += mx;
    }
    printf("%.8lf\n", res / 1. / n);
}