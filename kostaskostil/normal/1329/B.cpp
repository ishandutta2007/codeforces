#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int n, m;
int l[nmax];
int ans[nmax];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int d, m;
        cin>>d>>m;
        d++;
        vector<int> p2;
        p2.pb(1);

        for (int i=1; i<=30; i++)
        {
            int s=0;
            for (int j=0; j<i; j++)
                s=(s+p2[j]*(1ll<<j))%m;
            p2.pb(s);
        }
        int px2=1;
        int j=0;
        while (2*px2<=d)
        {
            px2*=2;
            j++;
        }
        int px=1;
        int ans=0;
        for (int i=0; i<=30; i++)
        {
            if (px==px2)
            {
                ans=(ans+(d+1-px)*p2[i])%m;
                break;
            }
            else
                ans=(ans+(((d-(1<<(i+1)))*(1<<i))%m)*p2[i])%m;
            px*=2;
        }
        cout<<ans<<"\n";
    }
}