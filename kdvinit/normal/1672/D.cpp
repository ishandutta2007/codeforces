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

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    int f[n+1]={0};

    int bi=n;

    for(int i=n; i>=1; i--)
    {
        if(bi!=0)
        {
            if(a[i]==b[bi])
            {
                int x=b[bi];
                while(bi!=0 && b[bi]==x) { f[x]++; bi--; }
                f[x]--;
            }
            else
            {
                if(f[a[i]]!=0) f[a[i]]--;
                else return false;
            }
        }
        else
        {
            if(f[a[i]]!=0) f[a[i]]--;
            else return false;
        }
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