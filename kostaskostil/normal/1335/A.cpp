#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=5e5+100;

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
        cout<<((n-1)/2)<<"\n";
    }
    return 0;
}