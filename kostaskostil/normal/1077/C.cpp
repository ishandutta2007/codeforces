#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;

map<int, int> m;
int a[200500];
vector<int> q;

main()
{
    cin>>n;
    int x;
    int ans=0;
    int s=0;
    for (int i=1; i<=n; i++)
        cin>>a[i], m[a[i]]++, s+=a[i];
    for (int i=1; i<=n; i++)
    {
        int s0=s-a[i];
        if (s0%2==0)
        {
            m[a[i]]--;
            if (m[s0/2]>0)
                ans++, q.pb(i);
            m[a[i]]++;
        }
    }
    cout<<ans<<"\n";
    for (int i:q)
        cout<<i<<" ";
    return 0;
}