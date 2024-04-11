#include <bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if ((c>b) or (c>a))
    {
        cout<<"-1\n";
        exit(0);
    }
    a=n-a-b+c;
    if ((a<=0) or (a>n))
        cout<<"-1\n";
    else
        cout<<a<<"\n";
    return 0;
}