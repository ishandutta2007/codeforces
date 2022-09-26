#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

int a[300500];
int n;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {

    int d;
    cin>>n>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        int c=min(a[i], d/(i-1));
        d-=c*(i-1);
        a[1]+=c;

    }
    cout<<a[1]<<"\n";

    }
    return 0;
}