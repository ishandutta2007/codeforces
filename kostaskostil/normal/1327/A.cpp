#include <bits\stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin>>n>>k;
        if ((n>=k*k) and ((n-k)%2==0))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}