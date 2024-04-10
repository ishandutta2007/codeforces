/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 3e5 + 100;

int n, q, mod;
int fib[N], del[N];
int not0;

void adjust(int &x)
{
    x = ((x%mod)+mod)%mod;
    return;
}

void add(int x, int l, int r)
{
    if(del[l]!=0) not0--;
    if(del[r+1]!=0) not0--;
    if(del[r+2]!=0) not0--;

    del[l]=(del[l]+x);
    adjust(del[l]);

    int len = r-l+1;

    del[r+1] = del[r+1]-((fib[len]+fib[len-1])*x);
    adjust(del[r+1]);

    del[r+2] = del[r+2]-(fib[len]*x);
    adjust(del[r+2]);

    if(del[l]!=0) not0++;
    if(del[r+1]!=0) not0++;
    if(del[r+2]!=0) not0++;

    return;
}

void solve()
{
    cin>>n>>q>>mod;

    fib[0]=0;
    fib[1]=1%mod;
    for(int i=2; i<=n+2; i++) fib[i]=(fib[i-1]+fib[i-2])%mod;

    int a[n+3]={0};
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        a[i] = (a[i]+mod-x)%mod;
    }

    del[0]=0;   del[1]=a[1]%mod;
    for(int i=2; i<=n+2; i++)
    {
        int x = a[i]-a[i-1]-a[i-2];
        adjust(x);
        del[i] = x;
    }

    not0=0;
    for(int i=1; i<=n+2; i++)
    {
        if(del[i]!=0) not0++;
    }

    char c;
    int l, r;

    while(q--)
    {
        cin>>c>>l>>r;
        if(c=='A') add(1, l, r);
        else add(-1, l, r);

        if(not0==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}