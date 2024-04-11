#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;

main()
{
    int a, b;
    cin>>a>>b;

    int s=a;

    while (a>0)
    {
        s+=a/b;
        if (a<b)
            break;
        a=(a/b)+(a%b);
    }
    cout<<s<<"\n";
    return 0;
}