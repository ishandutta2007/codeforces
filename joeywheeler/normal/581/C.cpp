#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> c[10];
int t[105];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        c[x%10].push_back(x);
    }
    for (int i = 9; i >= 0; i--) {
        for (int x : c[i]) {
            int l = (10-i)%10;
            if (k >= l) {
                k -= l;
                t[x+l]++;
            } else t[x]++;
        }
    }
    FO(i,0,100) {
        while (t[i] && k >= 10) {
            t[i]--; t[i+10]++;
            k -= 10;
        }
    }
    int res = 0;
    FO(i,0,101) res += (i/10) * t[i];
    printf("%d\n", res);
}