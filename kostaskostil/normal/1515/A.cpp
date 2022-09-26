#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n, x;
        cin>>n>>x;
        set<int> s;
        int c=0;
        while (n--)
        {
            int x;
            cin>>x;
            c+=x;
            s.insert(x);
        }
        if (c==x)
        {
            cout<<"NO\n";
            continue;
        }
        int sum=0;
        vector<int> ans;

        while (s.size() > 0)
        {
            int t = *s.begin();
            if (s.size()==1)
            {
                ans.pb(t);
                s.erase(t);
                break;
            }
            int q = *next(s.begin());
            if (sum + t == x)
                t = q;
            sum+=t;
            s.erase(t);
            ans.pb(t);
        }
        cout<<"YES\n";
        for (int i: ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}