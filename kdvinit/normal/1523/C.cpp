#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<string> ans;
    string s="1";

    ans.push_back(s);

    vector<int> num;
    num.push_back(1);

    for(int i=2; i<=n; i++)
    {
        if(a[i]==1)
        {
            num.push_back(1);
        }
        else
        {
            while(1)
            {
                int x = num.back();
                num.pop_back();
                if(x==a[i]-1) break;
            }
            num.push_back(a[i]);
        }

        string s = to_string(num[0]);
        int m = num.size();
        for(int j=1; j<m; j++)
        {
            string x = to_string(num[j]);
            s+=".";
            s+=x;
        }
        ans.push_back(s);

    }

    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}