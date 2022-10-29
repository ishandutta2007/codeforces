#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1E5 + 10;
int n;
int a[MAXN], ans[MAXN];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans[1] = 1;
    for(int i = 2; i <= n; i++)
        if (a[i] >= a[i-1])
            ans[i] = ans[i-1] + 1;
        else
            ans[i] = 1;
    int tot = 0;
    for(int i = 1; i <= n; i++)
        tot = max(tot, ans[i]);
    printf("%d\n", tot);
    return 0;
}