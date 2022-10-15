/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 1e6+10;
int a[N][21], n, b[N];

int mxl(int ii)
{
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i][ii]==0) continue;

        int j=i;
        while(j<=n && a[j][ii]==1) j++;

        map<int, int> odd, even;

        int cur=0, l=0;
        even[cur]=0;

        for(int k=i; k<j; k++)
        {
            l++;
            int y = b[k];
            y = y>>(ii-1);
            cur^=y;
            if(l%2==1)
            {
               if(odd[cur]==0)  odd[cur]=l;
               int tmp = l-odd[cur];
               ans = max(ans, tmp);
            }
            else
            {
               if(even[cur]==0 && cur!=0)  even[cur]=l;
               int tmp = l-even[cur];
               ans = max(ans, tmp);
            }
        }

        i=j-1;
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x; b[i]=x;
        for(int j=1; j<=20; j++) { a[i][j]=(x%2); x/=2; }
    }

    int ans=0;
    for(int i=1; i<=20; i++)
    {
        int tmp = mxl(i);
        ans = max(ans, tmp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}