/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s; cin>>s;
    char a[10];
    int mx = 1<<10;

    int ans=10;
    for(int i=0; i<mx; i++)
    {
        int x=i;
        for(int j=0; j<10; j++)
        {
            a[j]='0'+(x%2);
            x/=2;
        }

        int flag=1;
        for(int j=0; j<10; j++)
        {
            if(s[j]=='0' && a[j]=='1') flag=0;
            if(s[j]=='1' && a[j]=='0') flag=0;
        }
        if(flag==0) continue;

        int t1=0, t2=0;
        for(int j=0; j<10; j++)
        {
            if(a[j]=='1')
            {
                if(j%2==0) t1++;
                else t2++;
            }

            x = (9-j);
            int p1 = (x/2);
            int p2 = x-p1;

            if(t1>(t2+p2)) ans = min(ans, j+1);
            if(t2>(t1+p1)) ans = min(ans, j+1);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}