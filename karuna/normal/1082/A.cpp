#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(){
    int t;
    scanf("%d", &t);

    for (int T=0;T<t;T++){
        int n, x, y, d;
        scanf("%d %d %d %d", &n, &x, &y, &d);

        if ((y-x) % d == 0) {
            printf("%d\n", abs((y-x)/d));
            continue;
        }

        int a=-1, b=-1;
        if ((y-1) % d == 0) {
            a = (x-1)/d + 1 + (y-1)/d;
        }
        if ((n-y) % d == 0) {
            b = (n-x)/d + 1 + (n-y)/d;
        }

        if (a == -1 && b==-1) printf("-1\n");
        else if (a==-1) printf("%d\n", b);
        else if (b==-1) printf("%d\n", a);
        else printf("%d\n", min(a, b));

    }
}