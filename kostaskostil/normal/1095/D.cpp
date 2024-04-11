#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int n;
pair<int, int> a[300500];
    vector<int> v;

main()
{
    cin>>n;
    if(n==3)
        return cout<<1<<' '<<2<<' '<<3<<endl, 0;
    for(int i=0; i<n; i++)
        cin>>a[i].fi>>a[i].se;
    v.pb(1);
    int c=1, q=1;
    while(1)
    {
        if(a[a[c-1].fi-1].fi == a[c-1].se || a[a[c-1].fi-1].se == a[c-1].se)
            v.pb(a[c-1].fi), c=a[c-1].fi;
        else
            v.pb(a[c-1].se), c=a[c-1].se;
        if(c==1)
            break;
    }
    v.pop_back();
    for(auto i:v)
        cout<<i<<' ';
}