#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

char T = 'e';
int n;
vector<int> c;
vector<pair<vector<string>, vector<string> > > a;

int ans = 0;

int try_()
{
    map<string, bool> mp;
//    random_shuffle(c.begin(), c.end());
    int s = 0;
    for (int i : c)
    {
        bool ok = true;
        for (string s0 : a[i].fi)
            if (mp.count(s0))
                if (!mp[s0])
                {
                    ok = false;
                    break;
                }
        if (!ok)
            continue;
        for (string s0 : a[i].se)
            if (mp.count(s0))
                if (mp[s0])
                {
                    ok = false;
                    break;
                }
        if (!ok)
            continue;
        for (string s0 : a[i].fi)
            mp[s0] = 1;
        for (string s0 : a[i].se)
            mp[s0] = 0;
        s++;
    }

    if (s > ans)
    {
        cout<<"Answer "<<s<<" has been found.\n";
        ofstream os(string{T}+".out");
        vector<string> vans;
        for (auto pa : mp)
            if (pa.se)
                vans.pb(pa.fi);
        os<<vans.size()<<" ";
        for (string s : vans)
            os<<s<<" ";
        os<<"\n";

        ans = s;
    }

    return s;
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    cout<<"BucketPotato\n";
}