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

    vector<int> Miner, Diamond;
    for(int i=1;i<=2*n;i++)
    {
        int x, y;
        cin>>x>>y;
        x = abs(x);
        y = abs(y);

        if(x==0) Miner.push_back(y);
        else Diamond.push_back(x);
    }

    sort(Miner.begin(), Miner.end());
    sort(Diamond.begin(), Diamond.end());

    double ans = 0;
    for(int i=0;i<n;i++)
    {
        double x = Miner[i];
        int j=i;

        //if(i==0) j=n-1;
        //else j=i-1;

        double y = Diamond[j];
        double z = x*x + y*y;
        ans+= sqrt(z);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    std::cout << std::setprecision(15); std::cout << std::fixed;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}