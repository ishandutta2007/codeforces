/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int dir[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;

        if(x=='L') dir[i]=-1;
        else dir[i]=1;
    }

    array<int, 2> num[n+1];
    for(int i=1; i<=n; i++)
    {
        num[i] = {a[i], i};
    }

    /*
    for(int j=0; j<n; j++)
    {
        cout<<num[j][0]<<" "<<num[j][1]<<endl;
    }
    */

    sort(num+1, num+n+1);

    vector<int> odd, even;

    int ans[n+1];
    for(int i=1; i<=n; i++) ans[i]=-1;

    /*
    for(int j=0; j<n; j++)
    {
        cout<<num[j][0]<<" "<<num[j][1]<<endl;
    }
    */

    for(int j=1; j<=n; j++)
    {
        int i = num[j][1];

        if(a[i]%2==0)
        {
            if(dir[i]==1)
            {
                even.push_back(i);
            }
            else
            {
                if(even.empty()==1)
                {
                    a[i] = -a[i];
                    even.push_back(i);
                }
                else
                {
                    int ind = even.back();

                    int tmp = (a[i]-a[ind])/2;
                    ans[i]=tmp;
                    ans[ind]=tmp;

                    even.pop_back();
                }
            }
        }
        else
        {
            if(dir[i]==1)
            {
                odd.push_back(i);
            }
            else
            {
                if(odd.empty()==1)
                {
                    a[i] = -a[i];
                    odd.push_back(i);
                }
                else
                {
                    int ind = odd.back();

                    int tmp = (a[i]-a[ind])/2;
                    ans[i]=tmp;
                    ans[ind]=tmp;

                    odd.pop_back();
                }
            }
        }
    }

    int xx = even.size();
    int yy = odd.size();

    for(int i = xx-1; i>=1; i-=2)
    {
        int x = even[i];
        int y = even[i-1];

        int tmp = (2*m - a[x] - a[y])/2;
        ans[x]=tmp;
        ans[y]=tmp;
    }

    for(int i = yy-1; i>=1; i-=2)
    {
        int x = odd[i];
        int y = odd[i-1];

        int tmp = (2*m - a[x] - a[y])/2;
        ans[x]=tmp;
        ans[y]=tmp;
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}