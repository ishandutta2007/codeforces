#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool ex[16];
int n, k;
char bf[4][100005];

int main() {
    scanf("%d %d", &n, &k);
    fo(i,0,n) {
        fo(j,0,k) scanf(" %c", &bf[j][i]);
    }
    fo(i,0,n) {
        int v = 0;
        fo(j,0,k) v |= (bf[j][i]-'0') << j;
        ex[v] = true;
    }
    fo(i,1,1<<(1<<k)) {
        int cnt[4] = {};
        fo(j,0,1<<k) if (i & (1<<j)) {
            //if (i == 5) printf("j = %d\n", j);
            if (!ex[j]) cnt[0] = -1e9;
            else {
                fo(l,0,k) if (j & (1<<l)) {
                    //if (i == 5) printf("%d--\n", l);
                    cnt[l]--;
                } else {
                    //if (i == 5) printf("%d--\n", l);
                    cnt[l]++;
                }
            }
        }
        //if (i == 5) {
            //fo(j,0,k) printf("%d ", cnt[j]);
            //printf("\n");
        //}
        bool bad = false;
        fo(j,0,k) {
            if (cnt[j] < 0) {
                bad = true;
            }
        }
        if (!bad) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}