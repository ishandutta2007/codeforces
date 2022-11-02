#include<bits/stdc++.h>
using namespace std;
int n, a[200005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        if(a[i] < 0) return puts("NO");
        while(a[i]>1) a[i] -= 2;
        a[i+1] -= a[i]; a[i] = 0;
    }
    if(a[n+1] < 0) return puts("NO");
    puts("YES");
}