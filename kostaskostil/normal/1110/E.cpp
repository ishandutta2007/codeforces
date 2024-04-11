#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int a[100500];
int t[100500];
int n;
vector<int> v1, v2;

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>t[i];
    if ((a[1]!=t[1]) or (a[n]!=t[n]))
        cout<<"No\n", exit(0);
    for (int i=1; i<n; i++)
        v1.pb(a[i+1]-a[i]), v2.pb(t[i+1]-t[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i=0; i<v1.size(); i++)
        if (v1[i]!=v2[i])
            cout<<"No\n", exit(0);
    cout<<"Yes\n";
    return 0;
}