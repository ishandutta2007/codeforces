/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int common_segment(int x1, int x2, int x3, int x4)
{
    int ans = min(x2, x4) - max(x1, x3);
    ans = max(ans, (int)0);
    return ans;
}

int common_area(int x1, int x2, int y1, int y2, int x3, int x4, int y3, int y4)
{
    int l = common_segment(x1, x2, x3, x4);
    int b = common_segment(y1, y2, y3, y4);
    int area = l*b;
    return area;
}

int common_3segment(int x[])
{
    int ans = min( min(x[2], x[4]), x[6] ) - max( max(x[1], x[3]), x[5] );
    ans = max(ans, (int)0);
    return ans;
}

int common_3area(int x[],int y[])
{
    int l = common_3segment(x);
    int b = common_3segment(y);
    int area = l*b;
    return area;
}

void solve()
{
    int x[7], y[7];

    for(int i=1; i<=6; i++) cin>>x[i]>>y[i];

    int covered = common_area(x[1], x[2], y[1], y[2], x[3], x[4], y[3], y[4]);
    covered += common_area(x[1], x[2], y[1], y[2], x[5], x[6], y[5], y[6]);
    covered -= common_3area(x, y);

    int white = (x[2]-x[1])*(y[2]-y[1]);

    if(white!=covered) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}