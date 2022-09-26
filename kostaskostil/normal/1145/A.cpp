#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second

int n;
int a[100500];

int f(int l, int r)
{
    for (int i=l; i<r; i++)
        if (a[i+1]<a[i])
            return 0;
    return r-l+1;
}

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int x=0;
    for (int l=1; l<=n; l*=2)
        for (int i=1; i+l-1<=n; i+=l)
            x=max(x, f(i, i+l-1));
    cout<<x<<"\n";
    return 0;
}