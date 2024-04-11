#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
#define fi first
#define se second
#define pb push_back
 
#define int long long
using namespace std;
 
int a[200500];
int n, k;
 
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    k=n-k+1;
    int s=0;
    int c=1;
    int l=0;
    int f=1;
    for (int i=1; i<=n; i++)
    {
        if (a[i]>=k)
        {
            s+=a[i];
            if (f==1)
                f=0;
            else
                c*=(l+1);
            c%=998244353;
            l=0;
        }
        else
            l++;
    }
    c%=998244353;
    cout<<s<<" "<<c<<"\n";
    return 0;
}