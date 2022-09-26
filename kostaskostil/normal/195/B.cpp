#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int a[100500];
vector<int> v;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin>>m>>n;
    if (n%2==0)
        for (int i=0; i<n/2; i++)
            v.pb(n/2-i), v.pb(n/2+i+1);
    else
    {
        v.pb(n/2+1);
        for (int i=0; i<n/2; i++)
            v.pb(n/2-i), v.pb(n/2+i+2);
    }
    for (int i=0; i<m; i++)
        cout<<v[i%n]<<"\n";
}