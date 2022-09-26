#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 1; _ <= ___; _++)
    {
        int n;
        cin>>n;
        if (n%10 == 9)
            cout<<n/10 + 1;
        else
            cout<<n/10;
        cout<<"\n";
    }
}