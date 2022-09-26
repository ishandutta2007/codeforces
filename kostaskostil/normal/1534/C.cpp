#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n;
        cin>>n;
        vector<int> v(n), u(n);
        for (int& i : v)
            cin>>i, i--;
        for (int& i : u)
            cin>>i, i--;
        vector<int> rv(n), ru(n);
        for (int i=0; i<n; i++)
            rv[v[i]] =i;
        for (int i=0; i<n; i++)
            ru[u[i]] =i;
        vector<int> used(n, 0);
        int ans=0;
        for (int i=0; i<n; i++)
            if (!used[i])
        {
            ans++;
            int j = i;
            while (true)
            {
                used[j] = 1;
                j = rv[u[j]];
                if (j==i)
                    break;
            }
        }
        int res = 1;
        while (ans--)
        {
            res*=2;
            res%=(1000000007);
        }
        cout<<res<<"\n";
    }
}