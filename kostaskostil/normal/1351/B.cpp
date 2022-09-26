#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

bool check(int a, int b, int c, int d)
{
    return ((a==c) and (a==b+d));
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int a1, b1, a2, b2;
        cin>>a1>>b1>>a2>>b2;
        if (check(a1, b1, a2, b2) or check(a1, b1, b2, a2) or
            check(b1, a1, a2, b2) or check(b1, a1, b2, a2))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}