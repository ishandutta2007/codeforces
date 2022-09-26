#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int s=0;
    vector<pair<int, int> > a;
    for (int i=0; i<k; i++)
    {
        int x, y;
        cin>>x>>y;
        a.pb({x, y});
        s+=y;
    }
    if (s<n)
    {
        cout<<1<<"\n";
        return 0;
    }
    else if (s>n)
    {
        cout<<-1<<"\n";
        return 0;
    }
    sort(a.begin(), a.end());

    int sum=0;
    int cnt=0;
    for (int i=0; i+1<k; i++)
    {
        cnt+=a[i].se;
        sum+=(a[i+1].fi - a[i].fi)*cnt;
//        cout<<cnt<<" "<<sum<<"\n";
//        cout<<sum<<"\n";
    }
//    cnt+=a[k-1].se;
//    sum+=(n+a[0].fi-a[k-1].fi)*cnt;
    if ( (sum-(n*(n-1)/2))%n == 0)
        cout<<1<<"\n";
    else
        cout<<-1<<"\n";
}