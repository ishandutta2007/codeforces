#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
using namespace std;

typedef long long ll;

#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> h(n);
        vector<int> d(n);
        for (int i=0; i<n; i++)
            cin>>h[i]>>d[i];
        for (int i=0; i<n; i++)
            d[i]=min(d[i], h[(i+1)%n]);
        int s=0;
        int mn=1e18;
        for (int i=0; i<n; i++)
            s+=(h[i]-d[i]), mn=min(mn, d[i]);
        cout<<s+mn<<"\n";
    }
    return 0;
}