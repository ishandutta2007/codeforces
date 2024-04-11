#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=5e5+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        int a=0;
        for (int i=1; i<=n; i++)
            if (i<n/2 or i==n)
                a+=(1ll<<i);
            else
                a-=(1ll<<i);
        cout<<a<<"\n";
    }
}