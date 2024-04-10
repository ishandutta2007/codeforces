/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5001;

int ans[N];
int xy[N][2];

bool acute(int i)
{
    int x=ans[i];
    int y=ans[i+1];
    int z=ans[i+2];

    int val=( (xy[z][0]-xy[y][0])*(xy[y][0]-xy[x][0]) + (xy[z][1]-xy[y][1])*(xy[y][1]-xy[x][1]) );

    if(val<0) return true;
    else return false;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=1;i<=n;i++) cin>>xy[i][0]>>xy[i][1];

    int i=1;
    while(i!=n-1)
    {
        if(acute(i)) { i++; continue; }

        swap(ans[i+1],ans[i+2]);
        if(i==1) { i++; continue; }
        i--;
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}