#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int ___;
//    cin>>___;
//    for (int _=0; _<___; _++)
//    {
//
//    }

    int n, q;
    int cnt=0;
    cin>>n>>q;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin>>v[i];;
        cnt+=v[i];
    }
    while (q--)
    {
        int tp, x;
        cin>>tp>>x;
        if (tp==2)
            cout<<(cnt>=x)<<"\n";
        else
        {
            x--;
            cnt-=v[x];
            v[x]=1-v[x];
            cnt+=v[x];
        }
    }
}