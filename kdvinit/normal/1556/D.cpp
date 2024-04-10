/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int q;

int qor(int i, int j)
{
    cout<<"or "<<i<<" "<<j<<endl;
    cin>>q;
    return q;
}

int qand(int i, int j)
{
    cout<<"and "<<i<<" "<<j<<endl;
    cin>>q;
    return q;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    int orr[n+1];
    for(int i=2; i<=n; i++) orr[i] = qor(1, i);

    int andd[n+1];
    for(int i=2; i<=n; i++) andd[i] = qand(1, i);

    int abc = andd[2]&andd[3];

    int bc = qand(2, 3);
    bc -= abc;

    int x = orr[2]&orr[3];
    x -= bc;

    int a[n+1];
    a[1] = x;

    for(int i=2; i<=n; i++)
    {
        a[i] = orr[i] - (x-andd[i]);
    }

    sort(a+1, a+n+1);
    cout<<"finish "<<a[k]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}