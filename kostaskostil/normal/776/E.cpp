#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

int phi(int x)
{
    int s=1;
    for (int i=2; i*i<=x; i++)
        if (x%i==0)
    {
        s*=i-1;
        x/=i;
        while (x%i==0)
            s*=i, x/=i;
    }
    if (x>1)
        s*=x-1;
    return s;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    for (int i=0; i<(k+1)/2; i++)
    {
        n=phi(n);
        if (n==1)
            break;
    }
    cout<<n%1000000007<<"\n";
    return 0;
}