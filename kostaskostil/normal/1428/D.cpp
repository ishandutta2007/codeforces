#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v)
            cin>>i;
        vector<pair<int, int> > ans;
        vector<int> t3;
        vector<int> t2;
        int h=n;
        int x=-1;
        for (int i : v)
        {
            h--;
            x++;
            if (i==0)
                continue;
            if (i==1)
            {
                if (t2.size()>0)
                    ans.pb({x, t2.back()}), t2.pop_back();
                else
                if (t3.size()>0)
                {
                    ans.pb({x, t3.back()}), t3.pop_back();
                    ans.pb({x, h});
                }
                else
                    ans.pb({x, h});
                continue;
            }

            if (t3.size()>0)
                ans.pb({x, t3.back()}), t3.pop_back();
            ans.pb({x, h});

            if (i==2)
            {
                t2.pb(h);
            }
            else
            {
                t3.pb(h);
            }

        }

        if (!t2.empty() or !t3.empty())
            cout<<-1<<"\n";
        else
        {
            cout<<ans.size()<<"\n";
            for (auto pa:ans)
                cout<<n-pa.se<<" "<<pa.fi+1<<"\n";
        }
}