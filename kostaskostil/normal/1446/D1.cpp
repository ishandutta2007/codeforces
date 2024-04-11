#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=200500;
typedef long long ll;
#define int ll

int n;
int S = nmax;
int one[nmax];
int help[2*nmax];
int largestzero()
{
    for (int i=0; i<2*nmax; i++)
        help[i]=1e9;
    help[S+0]=0;
    int ans=0;
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        sum+=one[i];
        ans=max(ans, i-help[S+sum]);
        help[S+sum]=min(i, help[S+sum]);
    }
    return ans;
}

int a[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<pair<int, int> > v(101);
    for (int i=1; i<=100; i++)
        v[i].se=i;
    for (int i=1; i<=n; i++)
        v[a[i]].fi++;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int mx=v[0].se;
    if (v[0].fi==n)
    {
        cout<<0<<"\n";
        return 0;
    }

//    cout<<mx<<"\n";

    int ans=2;
    for (int i=1; i<=100; i++)
        if (i!=mx)
    {
        for (int j=1; j<=n; j++)
            if (a[j]==mx) one[j]=1;
            else if (a[j]==i) one[j]=-1;
            else one[j]=0;
//        cout<<i<<" "<<largestzero()<<"\n";
        ans=max(ans, largestzero());
    }
    cout<<ans<<"\n";
}