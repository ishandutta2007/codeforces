#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int n;
int a[300500];
    vector<int> v;

main()
{
    int n, k;
    cin>>n>>k;
    if (k>n)
    {
        cout<<"NO\n";
        return 0;
    }
    for (int i=40; i>=0; i--)
    {
        if (n>=(1ll<<i))
            v.pb(1ll<<i), n-=(1ll<<i);
        //cout<<n<<i<<(1<<i)<<"\n";
    }
   // for (int i:v)
   //     cout<<i<<" ";

    if (k<v.size())
        cout<<"NO\n";
    else
    {
        k-=v.size();
        for (int i=0; i<v.size(); i++)
        {
            while ((k>0) and (v[i]>1))
            {
                k--;
                v[i]/=2;
                v.pb(v[i]);
            }
        }
        cout<<"YES\n";
        for (int i:v)
            cout<<i<<" ";

    }
    return 0;
}