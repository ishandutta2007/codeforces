#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_--)
    {
        int n, k;
        cin>>n>>k;
        map<int, vector<int> > mp;
        for (int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            mp[x].pb(i);
        }
        vector<vector<int> > ans(k);
        int cur = 0;
        for (auto& pa : mp)
        {
            for (size_t i = 0; i < pa.se.size(); i++)
            {
                if (i>=k)
                    break;
                ans[cur].pb(pa.se[i]);
                cur++;
                cur%=k;
            }
        }
        int answ = 1e9;
        for (int i=0; i<k; i++)
            answ=min<int>(answ, ans[i].size());
        vector<int> col(n);
        for (int i=0; i<k; i++)
            for (int j=0; j<answ; j++)
                col[ans[i][j]]=i+1;
        for (int i: col)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}