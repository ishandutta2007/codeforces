/*
K.D. Vinit  |,,|
Don't Stalk My Code :)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    array<int, 2> a[n+1];
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        a[i][0]=x;
        a[i][1]=i;
    }
    sort(a+1,a+n+1);

    vector<int> SSC;
    SSC.push_back(0);

    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i][0];
        int ic2 = (i*(i-1))/2;
        if(sum==(ic2)) SSC.push_back(i);
    }

    int ans=0, x=0, y=0;
    for(int i=1; i<SSC.size(); i++)
    {
        int u = SSC[i-1]+1;
        int v = SSC[i];

        if(u==v) continue;
        int tmp = a[v][0] - a[u][0];
        if(tmp>=ans)
        {
            ans = tmp;
            x = a[u][1];
            y = a[v][1];
        }
    }

    cout<<"! "<<x<<" "<<y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}