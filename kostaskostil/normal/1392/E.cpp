#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int> > v(2*n, vector<int>(2*n, 0));
    for (int i=1; i<2*n-1; i++)
    {
        for (int j=0; j<=i; j++)
            if (j%2==0)
                v[j][i-j]=(1ll<<(i-1));
    }
    for (int i=0; i<n; i++, cout<<endl)
    for (int j=0; j<n; j++)
    cout<<v[i][j]<<" ";

    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        int x=1;
        int y=1;
        cout<<x<<" "<<y<<endl;
        for (int i=1; i<2*n-1; i++)
        {
            if (t%2 == 0)
            {
                if (x%2==0) y++;
                else x++;
            }
            else
            {
                if (x%2==0) x++;
                else y++;
            }
            cout<<x<<" "<<y<<endl;
            t/=2;
        }
    }

//    int qqq;
//    cin>>qqq;
//    for (int iii=0; iii<qqq; iii++)
//    {
//        int n, k;
//        cin>>n;
//        vector<int> v(n);
//        for (int& i:v) cin>>i;
//        reverse(v.begin(), v.end());
//        int ans=0;
//        for (int i=1; i<n; i++)
//            if (v[i]>v[i-1])
//                ans+=v[i]-v[i-1];
//            cout<<ans<<"\n";
//    }
    return 0;
}