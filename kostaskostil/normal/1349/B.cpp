#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;

int a[nmax];
int n, k;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=1; iii<=ttt; iii++){
        cin>>n>>k;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        if (n==1){
            if (k==a[1])
                cout<<"Yes\n";
            else cout<<"No\n";
            continue;
        }
        bool g=false;
        for (int i=1; i<=n; i++)
            if (a[i]==k)
                g=true;
        if (!g)
        {
            cout<<"No\n";
            continue;
        }
        g=false;
        for (int i=1; i<n; i++)
            if (a[i]>=k and a[i+1]>=k)
                g=true;
        for (int i=1; i<n-1; i++)
            if (a[i]>=k and a[i+2]>=k)
                g=true;
        if (g) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}