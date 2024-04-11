#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;

int a[1005000];
main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    a[0]=0;
    for (int i=1; i<n; i++)
        if ((s[i]=='v') and (s[i-1]=='v'))
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1];
    int ans=0;
    for (int i=1; i<n-1; i++)
        if (s[i]=='o')
            ans+=a[i-1]*(a[n-1]-a[i]);
    cout<<ans<<"\n";
}