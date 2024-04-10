#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bitset<4000> b[2000];
int n, m;
int x[500005], y[500005];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        scanf("%d%d", x+i, y+i); x[i]--; y[i]--;
        b[x[i]].set(y[i]);
    }
    FO(i,0,n) b[i].set(i+n);
    FO(i,0,n) {
        FO(j,i,n) if (b[j][i]) {
            swap(b[j], b[i]);
            break;
        }
        FO(j,0,n) if (j != i && b[j].test(i)) b[j] ^= b[i];
    }

    FO(i,0,m) if (b[y[i]].test(x[i]+n)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}