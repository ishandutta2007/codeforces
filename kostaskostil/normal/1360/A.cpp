#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int a, b, c, d;
        cin>>a>>b;
        if (a>b)
            swap(a, b);
        d=max(2*a, b);
        cout<<d*d<<"\n";
    }
}