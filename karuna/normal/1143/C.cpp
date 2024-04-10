#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
bool chk[101010];
int main() {
    scanf("%d", &n);

    int p, c;
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &p, &c);
        if (c==0)
            chk[i] = chk[p] = true;
    }

    bool is = false;
    for (int i=1; i<=n; i++) {
        if (chk[i] == false) {
            printf("%d ", i);
            is = true;
        }
    }

    if (is == false) {
        printf("-1");
    }
}