/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int dig(int r, int c)
{
    cout<<"DIG "<<r<<" "<<c<<endl;
    int ans; cin>>ans;
    return ans;
}

int scn(int r, int c)
{
    cout<<"SCAN "<<r<<" "<<c<<endl;
    int ans; cin>>ans;
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int q1 = scn(1, 1);
    int q2 = scn(n, 1);

    int sumc = (q1 + q2 - (2*n) + 6)/2;
    int sumr = q1 - sumc + 4;

    int rm = sumr/2;
    int cm = sumc/2;

    int q3 = scn(rm, 1);
    int q4 = scn(1, cm);

    int difr = q3 - sumc + 2;
    int difc = q4 - sumr + 2;

    int r1 = (sumr+difr)/2;
    int r2 = (sumr-difr)/2;

    int c1 = (sumc+difc)/2;
    int c2 = (sumc-difc)/2;

    if(dig(r1, c1)) dig(r2, c2);
    else { dig(r1, c2); dig(r2, c1); }

}

int32_t main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}