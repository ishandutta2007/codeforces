#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int a, b, k;
        cin>>a>>b>>k;
        if (k%2==0)
            cout<<(a-b)*(k/2)<<"\n";
        else
            cout<<(a-b)*(k/2)+a<<"\n";
    }
    return 0;
}