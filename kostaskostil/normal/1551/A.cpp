#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_--)
    {
        int n;
        cin>>n;
        int a=n/3;
        int b=n/3;
        if (n%3 == 1)
            a++;
        if (n%3 == 2)
            b++;
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}