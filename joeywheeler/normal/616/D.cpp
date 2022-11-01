#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f[1000005];
int nd;

void md(int a, int v) {
    if (f[a]) nd--;
    f[a] += v;
    if (f[a]) nd++;
}

int n, k;
int a[500005];

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,n) scanf("%d", a+i);
    int r = 0;
    md(a[0],1);
    int bl = 0, br = 0;
    FO(l,0,n) {
        // invariant [l,r] has <= k distinct
        while (r+1 < n) {
            r++;
            md(a[r],1);
            if (nd > k) {
                md(a[r],-1);
                r--;
                break;
            }
        }
        if (r-l > br-bl) {
            bl = l;
            br = r;
        }
        md(a[l],-1);
    }
    printf("%d %d\n", bl+1, br+1);
}