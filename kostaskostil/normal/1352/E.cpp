#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

int a[nmax];
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
            cin>>a[i], a[i]+=a[i-1];
        vector<bool> v(n*n+1, false);
        for (int i=1; i<=n; i++)
            for (int j=0; j<i-1; j++)
                v[a[i]-a[j]]=true;
        int c=0;
        for (int i=1; i<=n; i++)
            if (v[a[i]-a[i-1]])
                c++;
        cout<<c<<"\n";
    }

    return 0;
}