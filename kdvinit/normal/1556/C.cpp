/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int i=1; i<=n; i+=2)
    {
        int sum=0;
        int tmp = 0;
        for(int j=i+1; j<=n; j+=2)
        {
            //cout<<j<<" = "<<sum<<" -> "<<a[i]<<endl;
            int x = a[i], y = a[j];
            if(sum>0)
            {
                y-=sum;
                if(sum!=0 && y>=0) tmp++;
                y = max(y, (int)0);
            }

            tmp+=min(x, y);
            //cout<<j<<" = "<<tmp<<endl;

            sum-=a[j];
            if(sum<0)
            {
                a[i]+=sum;
                sum=0;
                if(a[i]<0) break;
            }
            sum+=a[j+1];
        }
        //cout<<i<<" -> "<<tmp<<endl;

        ans+=tmp;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}