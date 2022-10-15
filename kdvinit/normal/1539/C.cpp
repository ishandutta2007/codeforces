/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k, x;
    cin>>n>>k>>x;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    vector<int> need;
    for(int i=2; i<=n; i++)
    {
        int dif=a[i]-a[i-1];
        if(dif<=x) continue;
        int tmp = (dif-1)/x;
        need.push_back(tmp);
    }

    sort(need.begin(), need.end());

    int i=0;
    int len = need.size();

    while(1)
    {
        if(len==0 || k<=0) break;
        k-=need[i];
        i++;
        len--;
    }
    if(k<0) len++;
    cout<<(len+1)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}