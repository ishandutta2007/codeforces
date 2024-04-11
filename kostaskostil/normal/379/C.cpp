#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;

pair<int, int> a[300500];
int b[300500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].fi, a[i].se=i;
    sort(a+1, a+n+1);
    int c=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i].fi<=c)
            c++, b[a[i].se]=c;
        else
            b[a[i].se]=a[i].fi, c=a[i].fi;
    }

    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";


    return 0;
}