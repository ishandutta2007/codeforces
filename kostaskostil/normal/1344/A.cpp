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
    for (int i=0; i<ttt; i++)
    {
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>a[i];
        set<int> s;
        for (int i=0; i<n; i++)
        {
            s.insert(((i+a[i])%n+n)%n);
        }
if (s.size()==n)
    cout<<"YES\n";
else cout<<"NO\n";
    }

    return 0;
}