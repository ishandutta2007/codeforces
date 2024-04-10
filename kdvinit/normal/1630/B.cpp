/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int f[n+1]={0};
    for(int i=1; i<=n; i++) f[a[i]]++;

    int ps[n+1]={0};
    for(int i=1; i<=n; i++) ps[i] = ps[i-1]+f[i];

    int j=1;
    int av = n+1, al, ar;

    for(int i=1; i<=j; i++)
    {
        while(j!=n+1)
        {
            int x = ps[j]-ps[i-1];
            if(x < (n-x+k)) { j++; continue; }
            int len = j-i+1;
            if(len<av)
            {
                av=len;
                al=i;
                ar=j;
            }
            break;
        }
        if(j==n+1) break;
    }

    cout<<al<<" "<<ar<<endl;

    int sum=0;
    int cnt = 0;
    int lst = 0;

    for(int i=1; i<=n; i++)
    {
        if(cnt==k-1) break;

        if(al<=a[i] && a[i]<=ar) sum++;
        else sum--;

        if(sum<=0) continue;

        sum=0;
        cout<<lst+1<<" "<<i<<endl;
        lst=i;
        cnt++;
    }

    cout<<lst+1<<" "<<n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}