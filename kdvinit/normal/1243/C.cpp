/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    if(n==2) { cout<<2<<endl; return; }

    vector<int> factor;
    int m=sqrt(n)+1,cnt=0;
    int temp=n;
    for(int i=2;i<=m;i++)
    {
        if(temp%i!=0) continue;
        factor.push_back(i);
        cnt++;
        while(temp%i==0) temp/=i;
    }

    if(cnt==0) { cout<<n<<endl; return; }
    if(cnt==1 && temp==1) { cout<<factor[0]<<endl; return; }
    cout<<1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}