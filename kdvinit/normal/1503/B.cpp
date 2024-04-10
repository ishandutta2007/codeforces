/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    stack< array<int, 2> > odd;
    stack< array<int, 2> > even;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if( (i+j)%2==1 ) odd.push({i, j});
            else even.push({i, j});
        }
    }

    int ans[n+1][n+1];

    int done=0;
    for(int i=1; i<=n*n; i++)
    {
        int a; cin>>a;

        if(done==0)
        {
            if(a==1)
            {
                auto x = odd.top();
                odd.pop();

                cout<<2<<" "<<x[0]<<" "<<x[1]<<endl;
                ans[x[0]][x[1]]=2;

                if(odd.empty()) done=2;
            }
            else
            {
                auto x = even.top();
                even.pop();

                cout<<1<<" "<<x[0]<<" "<<x[1]<<endl;
                ans[x[0]][x[1]]=1;

                if(even.empty()) done=1;
            }
        }
        else
        {
            if(done==1)
            {
                auto x = odd.top();
                odd.pop();

                int y=2;
                if(a==2) y=3;

                cout<<y<<" "<<x[0]<<" "<<x[1]<<endl;
                ans[x[0]][x[1]]=y;
            }
            else
            {
                auto x = even.top();
                even.pop();

                int y=1;
                if(a==1) y=3;

                cout<<y<<" "<<x[0]<<" "<<x[1]<<endl;
                ans[x[0]][x[1]]=y;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}