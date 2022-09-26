#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        set<int> notones;
        int n;
        cin>>n;
        vector<int> a(n);
        int ans=0;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            if (a[i]!=1)
                notones.insert(i);
        }
        for (int i=0; i<n; i++)
        {
            if (a[i] > n)
            {
                ans+=a[i]-n, a[i]=n;
                if (n==1)
                    notones.erase(i);
            }
            for (int j=i+a[i]; j>i+1; j--)
            {
                ans++;
                int pos = j;
                while (pos < n)
                {
                    int pw = a[pos];
                    if (a[pos]==2)
                        notones.erase(pos);
                    a[pos]=max(a[pos]-1, 1ll);

                    if (pw == 1)
                    {
                        auto it = notones.lower_bound(pos);
                        if (it == notones.end())
                            pos = n+1;
                        else
                            pos = *it;
                    }
                    else
                        pos+=pw;
                }
            }
        }
        cout<<ans<<"\n";
    }

}