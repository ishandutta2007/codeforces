#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bool isp[1000005];

int main() {
    FO(i,2,1000005) isp[i] = true;
    FO(i,2,1000005) if (isp[i]) {
        for (int j = 2*i; j < 1000005; j += i) {
            isp[j] = false;
        }
    }
    int n; scanf("%d", &n);
    FO(m,1,1001) if (!isp[n*m+1]) {
        printf("%d\n", m);
        return 0;
    }
}