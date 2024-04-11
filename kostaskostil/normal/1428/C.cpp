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

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        string s;
        vector<char> v;
        cin>>s;
        int n=s.size();
        for (char c:s)
        {
            if ( c=='B' )
            {
                if (v.size() > 0)
                    v.pop_back();
                else
                    v.pb(c);
            }
            else
                v.pb(c);
        }
        cout<<v.size()<<"\n";
    }
}