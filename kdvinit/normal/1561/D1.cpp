/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e6+1;
int xtra[N];

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) xtra[i]=0;

    int sum=0;
    int cur;
    for(int i=1; i<=n; i++)
    {
        cur=(i==1);
        cur+=sum;               cur%=m;
        xtra[i]+=xtra[i-1];     xtra[i]%=m;
        cur+=xtra[i];           cur%=m;
        int k=2;
        for(int j=(2*i); j<=n; j+=i, k++)
        {
            xtra[j]+=cur;       xtra[j]%=m;
            int nd = j+k;
            if(nd<=n) { xtra[nd]-=cur; xtra[j]%=m; }
        }
        sum+=cur;               sum%=m;
    }
    if(cur<0) cur+=m;
    cout<<cur<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}