#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int l[100005], r[100005], q[100005];
int s[100005];
int c[100005];
int ans[100005];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        scanf("%d %d %d", l+i, r+i, q+i);
        l[i]--;
    }
    FO(B,0,31) {
        memset(s,0,sizeof s);
        FO(i,0,m) if (q[i] & (1<<B)) {
            s[l[i]]++;
            s[r[i]]--;
        }
        FO(i,1,n+1) s[i] += s[i-1];
        FO(i,0,n+1) if (s[i] > 0) s[i] = 1;
        FO(i,1,n+1) c[i] = c[i-1] + s[i-1];
        bool good = true;
        FO(i,0,m) if (q[i] & (1<<B)) {
            good &= c[r[i]]-c[l[i]] == r[i]-l[i];
        } else {
            good &= c[r[i]]-c[l[i]] != r[i]-l[i];
        }
        if (good) {
            FO(i,0,n) if (s[i]) ans[i] |= 1<<B;
        } else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    FO(i,0,n) printf("%d ", ans[i]);
    printf("\n");
}