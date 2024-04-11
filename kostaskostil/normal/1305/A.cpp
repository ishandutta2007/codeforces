#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

#define int long long

const int nmax=5e5+100;
int a[nmax];
int b[nmax];
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
        for (int i=1; i<=n; i++)
            cin>>a[i];
        for (int i=1; i<=n; i++)
            cin>>b[i];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        for (int i=1; i<=n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        for (int i=1; i<=n ;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
    return 0;
}