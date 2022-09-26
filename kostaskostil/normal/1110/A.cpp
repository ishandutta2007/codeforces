#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int ppow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
}

main()
{
    int k, n;
    int x;
    int t=0;
    cin>>k>>n;
    for (int i=n-1; i>=0; i--)
        cin>>x, t+=x*ppow(k, min(i, 1ll));
    if (t%2==0)
        cout<<"even\n";
    else
        cout<<"odd\n";
    return 0;
}