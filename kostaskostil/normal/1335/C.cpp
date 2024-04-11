#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=2e5+100;
int a[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        map<int, int> mp;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i], mp[a[i]]++;
        int a=mp.size();
        int b=0;
        for (auto pa:mp)
            b=max(b, pa.second);
        if (a==b)
            cout<<a-1<<"\n";
        else
            cout<<min(a, b)<<"\n";
    }
    return 0;
}