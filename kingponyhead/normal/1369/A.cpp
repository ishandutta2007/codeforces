// Screw this ..
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        int n;
        scanf("%d", &n);
        puts(n % 4 ? "NO" : "YES");
    }
    return 0;
}