#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=200500;

int a[nmax];
int n, k;

bool check()
{
    map<int, int> mp;
    for(int i=1; i<=n; i++)
        mp[a[i]]++;
    for (auto pa:mp)
        if (pa.se>=k)
            return true;
    return false;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    if (check())
    {
        cout<<"0\n";
        return 0;
    }

        sort(a+1, a+n+1);

        int s=0;
        for (int i=1; i<=n; i++)
            s+=abs(a[i]-a[(n+1)/2]);
        s-=(n-k);

        int s1=0, s2=0;
        for (int i=1; i<=k; i++)
            s1+=a[k]-a[i];
        for (int i=k+1; i<=n; i++)
            if (a[i]==a[k])
                s1--;

        for (int i=n-k+1; i<=n; i++)
            s2+=a[i]-a[n-k+1];
        for (int i=1; i<=n-k; i++)
            if (a[i]==a[n-k+1])
                s2--;
        cout<<min(min(s1, s2), s)<<"\n";

}