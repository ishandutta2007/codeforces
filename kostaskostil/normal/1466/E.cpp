#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 2e5 + 100;

typedef long long ll;
#define int ll
const int cmax = 61;
const int MOD = 1e9+7;
int pw[cmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    for (int i=1; i<cmax; i++)
        pw[i]=(2*pw[i-1])%MOD;

    int ___;
    cin>>___;
    for (int _ = 0; _ < ___; _++)
    {
        int n;
        cin>>n;
        vector<int> x(n);
        for (int& i: x)
            cin>>i;
        vector<int> cnt(cmax, 0);
        for (int i:x)
            for (int j=0; j<cmax; j++)
                if ((i>>j)&1)
                    cnt[j]++;
        int sum = 0;
        for (int j:x)
        {
            int sor = 0;
            for (int i=0; i<cmax; i++)
            {
                if ((j>>i)&1)
                    sor += n*pw[i];
                else
                    sor += cnt[i]*pw[i];
                sor%=MOD;
            }

            int sand = 0;
            for (int i=0; i<cmax; i++)
            {
                if ((j>>i)&1)
                    sand += cnt[i]*pw[i];
                else
                    sand += 0;
            }
            sand%=MOD;

            sum+=sor*sand;
            sum%=MOD;
        }

        cout<<sum<<"\n";
    }
}