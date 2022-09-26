#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;
const int nmax=5e5+100;
int a[nmax];
int b[nmax];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        b[1]=a[1];
        for (int i=2; i<=n; i++)
            b[i]=max(b[i-1], a[i]);
        int mx=0;
        for (int i=1; i<=n; i++)
            mx=max(mx, b[i]-a[i]);
        int c=0;
        while (mx>0)
            c++, mx/=2;
        cout<<c<<"\n";
    }



    return 0;
}