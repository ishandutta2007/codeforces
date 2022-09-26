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
    for (int _=0; _<___; _++)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<int> a;
        int l=-1;
        int r=-1;
        int cnt=0;
        int cnt0=0;
        int ans=0;
        for (size_t i=0; i<n; i++)
        {
            if (s[i]=='W')
            {
                ans++;
                if (i>0)
                    if (s[i-1]=='W')
                        ans++;

                r=i;
                if (l==-1)
                    l=i;
                else
                {
                    if (cnt>0)
                        a.pb(cnt);
                }
                cnt=0;
            }
            else
            {
                cnt++;
                cnt0++;
            }
        }
        if (n==1)
        {
            if (k==0)
                cout<<ans<<"\n";
            else
                cout<<1<<"\n";
        }
        else
        if (cnt0<=k)
            cout<<2*n-1<<"\n";
        else
        if (cnt0==n)
        {
            if (k==0)
                cout<<0<<"\n";
            else
                cout<<2*k-1<<"\n";
        }
        else
        {
//            cout<<"p "<<ans<<"\n";
            sort(a.begin(), a.end());
            for (int i:a)
            {
                if (k>=i)
                {
                    ans+=(2*i+1);
                    k-=i;
                }
            }
            cout<<ans+2*k<<"\n";
        }
    }
}