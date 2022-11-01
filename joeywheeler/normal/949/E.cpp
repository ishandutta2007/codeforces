#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define MX 20
#define MXP (1<<25)

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    fo(i,0,n) {
        scanf("%d", a+i);
    }
    vector<int> res;
    int bs = 0;
    while (true) {
        bool need = false;
        fo(k,0,n) if (a[k]) need = true;
        if (!need) break;
        int j;
        for (j = 0; ; j++) {
            // use [0,j) to get all 0 mod 2^(j+1)
            int mod = 1<<(j+1);
            int l = 0, r = 0;
            fo(k,0,n) {
                int vl = (a[k] + MXP) & (mod-1);
                if (vl >= mod/2) vl -= mod;
                l = min(l, vl);
                r = max(r, vl);
            }
            if (r-l+1 <= (1<<j)) {
                fo(k,0,j) {
                    if (r&(1<<k)) {
                        res.push_back(1<<(k+bs));
                    } else {
                        res.push_back(-(1<<(k+bs)));
                    }
                }
                fo(k,0,n) {
                    int vl = (a[k] + MXP) & (mod-1);
                    if (vl >= mod/2) vl -= mod;
                    a[k] -= vl;
                    a[k] /= mod;
                }
                break;
            }
        }
        bs += j+1;
    }
    printf("%d\n", sz(res));
    for (int x : res) printf("%d ", x);
    printf("\n");
}