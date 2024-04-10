/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
bool check(int U, int x, int y)
{
    int p = U - x - y;
    if(p<0 || p>(n-2)) return false;
    else return true;
}

void solve()
{
    int U, R, D, L;
    cin>>n>>U>>R>>D>>L;

    int a[2][2];
    for(int i=0;i<16;i++)
    {
        int x=i;
        a[0][0]=x%2; x/=2;
        a[0][1]=x%2; x/=2;
        a[1][0]=x%2; x/=2;
        a[1][1]=x%2;

        if(!check(U, a[0][0], a[0][1])) continue;
        if(!check(R, a[1][1], a[0][1])) continue;
        if(!check(D, a[1][0], a[1][1])) continue;
        if(!check(L, a[0][0], a[1][0])) continue;

        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}