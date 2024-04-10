#include<bits/stdc++.h>
using namespace std;
int n, a[1005][1005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans += a[i][j]*a[j][i];
            ans %= 2;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--) {
        int typ;
        scanf("%d",&typ);
        if(typ==3) {
            printf("%d",ans);
        }
        else {
            int tmp;
            scanf("%d",&tmp);
            ans ^= 1;
        }
    }
}