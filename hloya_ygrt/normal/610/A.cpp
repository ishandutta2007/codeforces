#include <bits\stdc++.h>
using namespace std;
    const int maxn=2e5;
    const int eps=1e-8;
    const int inf=2e9;

    #define mp make_pair
    #define f first
    #define sec second
    #define pb push_back

    int a[maxn];

int main()
{
    int n;

    ///freopen("input.txt","r",stdin);

    scanf("%d",&n);
    if (n%2==1)
    {
        cout<<0;
        return 0;

    }
    int ans=n/4;

    if (n%4==0)
        ans--;
    cout<<ans;
    return 0;
}