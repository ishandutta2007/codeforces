#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int& i:v) cin>>i;
        k--;
        int mx=v[0];
        for (int i=1; i<n; i++)
            mx=max(mx, v[i]);
        for (int& i:v) i=mx-i;
        k%=2;
        if (k>0)
        {
int mx=v[0];
        for (int i=1; i<n; i++)
            mx=max(mx, v[i]);
        for (int& i:v) i=mx-i;

        }
        for (int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}