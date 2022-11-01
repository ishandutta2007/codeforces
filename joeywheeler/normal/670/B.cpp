#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll n, k;
ll id[100005];

int main() {
    scanf("%lld%lld", &n, &k);
    FO(i,1,n+1) {
        scanf("%lld", id+i);
        if (k <= i) {
            printf("%lld\n", id[k]);
            return 0;
        } else {
            k -= i;
        }
    }
}