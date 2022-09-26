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
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        int l=-1;
        int r;
        for (int i=1; i<n; i++)
            if (abs(a[i]-a[i+1])>=2)
                l=i, r=i+1;
        if (l==-1)
            cout<<"NO\n";
        else
            cout<<"YES\n"<<l<<" "<<r<<"\n";
    }
    return 0;
}