#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200500];
int pr[400500];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, k;
        cin>>n>>k;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        for (int i=0; i<=2*k; i++)
            pr[i]=0;
        for (int i=1; i<=n/2; i++)
        {
            int x=a[i];
            int y=a[n+1-i];
            int smin=min(x, y)+1;
            int smax=max(x, y)+k;
            pr[x+y]++;
            pr[x+y-1]--;
            pr[smax]++;
            pr[smin-1]--;
        }
        for (int i=2*k-1; i>=0; i--)
            pr[i]+=pr[i+1];
        int mx=0;
        for (int i=0; i<=2*k; i++)
            mx=max(mx, pr[i]);
        cout<<n-mx<<"\n";
    }
}