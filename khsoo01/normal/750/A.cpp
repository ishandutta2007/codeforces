#include<bits/stdc++.h>
using namespace std;
int n, k, ans;

int main()
{
    scanf("%d%d",&n,&k);
    k = 240 - k;
    for(int i=1;i<=n;i++) {
        if(5 * i > k) break;
        k -= 5*i;
        ans++;
    }
    printf("%d\n",ans);
}