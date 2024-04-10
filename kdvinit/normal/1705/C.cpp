/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int C = 100+10;
const int N = 2e5 + 100;

int len[C];
int l[C], r[C];
char a[N];
int n, c, q;

char findx(int k, int d)
{
    if(d==0) return a[k];

    int pl=len[d-1];
    if(k<=pl) return findx(k, d-1);

    int cur=l[d]+(k-pl-1);
    return findx(cur, d-1);
}

void solve()
{
    cin>>n>>c>>q;
    for(int i=1; i<=n; i++) cin>>a[i];

    len[0]=n;
    for(int i=1; i<=c; i++)
    {
        cin>>l[i]>>r[i];
        int cur = r[i]-l[i]+1;
        len[i]=len[i-1]+cur;
    }

    for(int i=1; i<=q; i++)
    {
        int k; cin>>k;
        char x = findx(k, c);
        cout<<x<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}