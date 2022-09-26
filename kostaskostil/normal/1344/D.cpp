#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll
#define double long double
int n, k;
int a[nmax];

int border(int i, double M)
{
    int res=(1.0+sqrt(1+ 4.0/3.0*(a[i]+M)))/2.0;
    if (res<0) return 0;
    if (res>a[i]) return a[i];
    return res;
}

int need(double M)
{
    int s=0;
    for (int i=1; i<=n; i++)
    {
        s+=border(i, M);
        if (s>k)
            return k+1;
    }
    return s;
}

pair<double, double> finder()
{
    double l=-1e30;
    double r=1e30;
    while (r!=l)
    {
        double m=(l+r)/2;
        if ((m==l) or (m==r))
            return {l, r};
        int ans=need(m);
        if (ans>k)
            r=m;
        else if (ans<k)
            l=m;
        else
            return {m, -1.0};
    }
    return {l, r};
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];

//    int ans=0;
//    for (int i=1; i<=n; i++)
//    {
//        int x;
//        cin>>x;
//        ans+=x*(a[i]-x*x);
//    }
//    cout<<ans<<"\n";

    auto M=finder();
    if (M.second==-1.0)
    {
        for (int i=1; i<=n; i++)
            cout<<border(i, M.first)<<" ";
        cout<<"\n";
        exit(0);
    }
    vector<int> low, high;
    for (int i=1; i<=n; i++)
    {
        low.push_back(border(i, M.first));
        high.push_back(border(i, M.second));
    }
    int left=k-need(M.first);
    for (int i=0; i<n; i++)
    {
        if ((left==0) or (low[i]==high[i]))
            cout<<low[i]<<" ";
        else
            left--, cout<<low[i]+1<<" ";
    }
        cout<<"\n";
    return 0;
}