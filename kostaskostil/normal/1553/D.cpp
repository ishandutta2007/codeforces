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
    for (int _ = 1; _ <= ___; _++)
    {
        string s, t;
        cin>>s>>t;
        int n=s.size();
        int m=t.size();
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int cur = 0;
        for (int i = 0; (i < n) and (cur < m); i ++)
        {
            if (s[i] == t[cur])
                cur++;
            else
                i++;
        }
        if (cur == m)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}