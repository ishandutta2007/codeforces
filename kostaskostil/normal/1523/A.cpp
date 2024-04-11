#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 1e6 + 100;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        for (int i=0; i<m; i++)
        {
            string sx = s;
            for (int j=0; j<n; j++)
            {
                int c=0;
                if (j>0)
                    if (s[j-1] == '1')
                        c++;
                if (j<n-1)
                    if (s[j+1] == '1')
                        c++;
                if (c==1)
                    sx[j]='1';
            }
            if (s==sx)
                break;
            s=sx;
        }
        cout<<s<<"\n";
    }
}