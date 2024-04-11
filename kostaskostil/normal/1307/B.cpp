#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

int a[300500];
int n;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {

    int d;
    cin>>n>>d;
    int s=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==d)
            s=1;
    }
    sort(a+1, a+n+1);
    if (s==1)
        cout<<1<<"\n";
    else
    cout<<max(((d+a[n]-1)/a[n]), 2)<<"\n";

    }
    return 0;
}