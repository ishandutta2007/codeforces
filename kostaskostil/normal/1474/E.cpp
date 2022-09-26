#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 5e5+100;
int p[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int n;
        cin>>n;

        int ans=0;
        for (int i=2; i<n; i++)
            ans+=max(i-1, n-i)*max(i-1, n-i);
        ans+=(n-1)*(n-1);
        cout<<ans<<"\n";

        int k=n/2;
        p[1]=k+1;
        for (int i=k+1; i<n; i++)
            p[i]=i+1;
        p[n]=k;
        for (int i=k; i>1; i--)
            p[i]=i-1;

        for (int i=1; i<=n; i++)
            cout<<p[i]<<" ";
        cout<<"\n";
        cout<<n-1<<"\n";
        for (int i=k+1; i<n; i++)
            cout<<i<<" "<<1<<"\n";
        for (int i=k; i>1; i--)
            cout<<i<<" "<<n<<"\n";
        cout<<n<<" 1"<<"\n";
    }

	return 0;
}