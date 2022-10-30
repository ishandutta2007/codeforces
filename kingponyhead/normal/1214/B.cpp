// Long Live The King!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int main()
{
    int b, g, n, cnt = 0;
    scanf("%d%d%d", &b, &g, &n);
    for (int i= 0; i <= b; i ++)
        if (i <= n && i + g >= n)
            cnt ++;
    printf("%d\n", cnt);
}