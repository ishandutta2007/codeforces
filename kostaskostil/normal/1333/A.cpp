#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long

using namespace std;

main() {
    cerr<<"Does this really work?\n";
    int t;
    int n, m;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin>>n>>m;
        for (int i=0; i<n; i++, cout<<"\n")
            for (int j=0; j<m; j++)
                if (i==j and i==0)
                cout<<"W";
        else cout<<"B";
    }
}