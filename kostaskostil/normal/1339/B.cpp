#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        vector<int> v;
        cin>>n;
        v.resize(n);
        for (int i=0; i<n; i++)
            cin>>v[i];
        sort(v.begin(), v.end());
        if (n%2) cout<<v[n/2]<<" ";
        for (int i=0; i<n/2; i++)
            cout<<v[(n-2-2*i)/2]<<" "<<v[(n+1+2*i)/2]<<" ";
        cout<<"\n";
    }
    return 0;
}