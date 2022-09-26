#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

#define double long double
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(15);

    int ___;
    cin>>___;
    while (___--)
    {
        int n;
        cin>>n;
        vector<pair<int, int> > v;
        vector<pair<int, int> > u;
        for (int i=0; i<2*n; i++)
        {
            int x, y;
            cin>>x>>y;
            if (x==0)
                u.pb({x, y});
            else
                v.pb({x, y});
        }

        double ans1=0, ans2=0;
        sort(v.begin(), v.end(), [](pair<int, int> i, pair<int, int> j){return abs(i.fi)+abs(i.se) < abs(j.fi)+abs(j.se);});
        sort(u.begin(), u.end(), [](pair<int, int> i, pair<int, int> j){return abs(i.fi)+abs(i.se) < abs(j.fi)+abs(j.se);});
//        sort(u.begin(), u.end());

        for (int i=0; i<n; i++)
            ans1+=sqrt(  (v[i].fi-u[i].fi)*(v[i].fi-u[i].fi) + (v[i].se-u[i].se)*(v[i].se-u[i].se) );
        reverse(u.begin(), u.end());
        for (int i=0; i<n; i++)
            ans2+=sqrt(  (v[i].fi-u[i].fi)*(v[i].fi-u[i].fi) + (v[i].se-u[i].se)*(v[i].se-u[i].se) );
        cout<<min(ans1, ans2)<<"\n";
    }

}