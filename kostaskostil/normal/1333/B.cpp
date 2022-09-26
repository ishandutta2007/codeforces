#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        cout.tie(0);
    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        vector<int> a(n), b(n), up(n), dn(n);
        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=0; i<n; i++)
            cin>>b[i];
        for (int i=0; i<n; i++)
            if (a[i]==1)
        {
            for (int j=i+1; j<n; j++)
                up[j]=1;
            break;
        }
        for (int i=0; i<n; i++)
            if (a[i]==-1)
        {
            for (int j=i+1; j<n; j++)
                dn[j]=1;
            break;
        }
        bool f=true;
        for (int i=0; i<n; i++)
            if ((b[i]>a[i] and up[i]==0) or (b[i]<a[i] and dn[i]==0))
                f=false;
        if (f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}