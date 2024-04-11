#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

int n;
int a[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n, m, k1=-1, k2=-1;
        cin>>n>>n>>m;
        int x;
        for (int i=0; i<n; i++)
            cin>>x, k1=max(k1, x);
        for (int i=0; i<m; i++)
            cin>>x, k2=max(k2, x);
        if (k1>k2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}