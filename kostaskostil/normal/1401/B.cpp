#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int long long

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int a0, a1, a2, b0, b1, b2;
        cin>>a0>>a1>>a2>>b0>>b1>>b2;
        int p=min(a2, b1);
        a2-=p;
        b1-=p;
        int a3=a0+a2;
        int b3=b0+b1;
        int m=max(0ll, a1+b2 - (a1+a3));
        cout<<2*(p-m)<<"\n";
    }

    return 0;
}