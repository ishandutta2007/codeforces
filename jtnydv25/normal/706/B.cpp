#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+100;
int x[maxn];

int main()
{
    int n,q,m;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%d ", &x[i]);
    scanf("%d",&q);
    sort(x+1,x+n+1);
    while(q--)
    {
        scanf("%d",&m);
        int a = 1,b = n;
        //xi <= m
        while(a<b)
        {
            int mid = (a+b)>>1;
            if(x[mid] <= m)
                a = mid+1;
            else
                b = mid;
        }
        if(x[a]<=m)
            a++;
        printf("%d\n",a-1);
    }
}