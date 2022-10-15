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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> b;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(i<=n && a[i]==a[j]) i++;
        i--;
        b.push_back(a[i]);
    }
    int m=b.size();

    multiset<int> ms;
    for(int i=0;i<m;i++)
    {
        ans++;
        int x=b[i];
        if(ms.count(x)==1)
        {
            ans--;
            ms.clear();
            ms.insert(b[i-1]);
        }
        ms.insert(x);
    }

    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}