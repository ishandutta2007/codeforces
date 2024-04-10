#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a;
set<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n,r;
    cin>>t;
    while(t--)
    {v.clear();
        a.clear();
        cin>>n>>r;
        for(int i=0;i<n;i++){int x;cin>>x;a.push_back(x);v.insert(x);}
        sort(a.begin(),a.end());
        ll d=v.size(),ans=v.size();

        for(int i=0;i<n;i++)
            {if(i==0||a[i]!=a[i-1])d--;
                ll res=(a[i]+r-1)/r;
        res=max(res,d);ans=min(ans,res);}
        cout<<ans<<endl;


    }
    return 0;
}