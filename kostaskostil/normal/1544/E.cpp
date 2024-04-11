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

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        string s;
        cin>>s;
        int n = s.size();
        map<char, int> mp;
        for (char c : s)
            mp[c]++;

        bool ok = false;
        if (mp.size() == 1)
            ok = true;
        if (!ok)
        for (auto pa : mp)
            if (pa.se == 1)
            {
                for (int i=1; i<n; i++)
                    if (s[i] == pa.fi)
                        swap(s[i], s[0]);
                sort(s.begin() + 1, s.end());
                ok = true;
                break;
            }
        if (!ok)
        {
            char c0 = mp.begin()->fi;
            int n0 = mp.begin()->se;
            if (n0 > n/2 + 1)
            {
                char c1 = next(mp.begin())->fi;
                int n1 = next(mp.begin())->se;
                if (mp.size() == 2)
                {
                    s = c0;
                    for (int i=0; i<n1; i++)
                        s+=c1;
                    for (int i=1; i<n0; i++)
                        s+=c0;
                }
                else
                {
                    string t;
                    t = c0;
                    t+=c1;
                    for (int i=1; i<n0; i++)
                        t+=c0;
                    char c2 = next(next(mp.begin()))->fi;
                    t+=c2;
                    mp[c1]--;
                    mp[c2]--;
                    mp[c0]=0;
                    for (auto pa : mp)
                        for (int i=0; i<pa.se; i++)
                            t+=pa.fi;
                    s = t;
                }
            }
            else
            {
                string t = "";
                for (char c : s)
                    if (c!=c0)
                        t+=c;
                sort(t.begin(), t.end());
                s = c0;
                s+= c0;
                n0-=2;
                for (size_t i=0; i<t.size(); i++)
                {
                    s+=t[i];
                    if (n0 > 0)
                        s+=c0, n0--;
                }
            }
        }
        cout<<s<<"\n";
    }
}