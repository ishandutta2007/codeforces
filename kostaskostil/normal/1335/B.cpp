#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=2e5+100;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n, a, b;
        cin>>n>>a>>b;
        for (int i=0; i<n; i++) {
            int c=(i%a);
            if (c<b)
                cout<<char('a'+c);
            else
                cout<<char('a'+b-1);
        }
        cout<<"\n";
    }
    return 0;
}