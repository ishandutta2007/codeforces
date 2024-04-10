/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int a15=0;
    for(int i=1; i<=n; i++) if(a[i]%5==0) { a15=1; break; }

    if(a15)
    {
        for(int i=1; i<=n; i++) if(a[i]%5!=0) return false;

        int p1 = a[1];
        int p2 = a[1]+(a[1]%10);

        for(int i=1; i<=n; i++)
        {
            if(a[i]==p1 || a[i]==p2) continue;
            int x = a[i] + (a[i]%10);
            if(x==p1 || x==p2) continue;
            return false;
        }

        return true;
    }

    int mn=a[1]+1000;
    for(int i=1; i<=n; i++)
    {
        int x=a[i];
        while(1)
        {
            int y=x%10;
            if(y==2) break;
            x+=y;
        }
        a[i]=x;
        mn=min(mn, a[i]);
    }

    for(int i=1; i<=n; i++)
    {
        int x = a[i]-mn;
        if(x%20!=0) return false;
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}