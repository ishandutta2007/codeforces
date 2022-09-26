#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int a[100500];
int b[100500];

main()
{
    int n, m, k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (k==n)
        cout<<n<<"\n", exit(0);

    int s=a[n]-a[1]+1;
    for (int i=1; i<n; i++)
        b[i]=a[i+1]-a[i];
    sort(b+1, b+n);
    for (int i=n-1; i>n-k; i--)
        s-=(b[i]-1);
    cout<<s<<"\n";
    return 0;
}