#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int i=0; i<ttt; i++)
    {
        int a, b, n;
        cin>>a>>b>>n;
        int c=0;
        while ((a<=n) and (b<=n))
        {
            if (a>b)
                swap(a, b);
            a+=b;
            c++;
        }
        cout<<c<<"\n";
    }
}