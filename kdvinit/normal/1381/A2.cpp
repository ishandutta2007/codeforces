#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ya cout<<"YES\n"
#define na cout<<"NO\n"
#define pub push_back
#define mp make_pair
#define pob pop_back

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string a,b;
        cin>>a>>b;
        cout.flush();

        vector<int>v,x;

        int e=0,f=0;



        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                e=1;
                v.pub(i);
            }
        }
        for(int i=1;i<n;i++)
        {
            if(b[i]!=b[i-1])
            {
                f=1;
                x.pub(i);
            }
        }
        if(a[n-1]!=b[n-1])
        {
            e=1;
            v.pub(n);
        }

        int ans=0;
        if(e==1) ans+=v.size();
        if(f==1) ans+=x.size();
        cout<<ans<<" ";
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }

        int m=x.size();
        for(int i=m-1;i>=0;i--)
        {
            cout<<x[i]<<" ";
        }
        cout<<" ";
    }
}