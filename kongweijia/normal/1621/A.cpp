#include<bits/stdc++.h>
using namespace std;
int n,k;
void solve() {
    scanf("%d%d",&n,&k);
    if ((n+1>>1)<k)
        puts("-1");
    else
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (i==j&&!(i%2)&&k<<1>i)
                    printf("R");
                else
                    printf(".");
            puts(" ");
        }
}
int main() {
    int t; scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}