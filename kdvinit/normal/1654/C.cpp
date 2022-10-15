/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

map<int, int> mp;
int cnt=0;
int n;

bool check(int sum)
{
    if(mp[sum]!=0)
    {
        mp[sum]--;
        return true;
    }
    if(sum==1) return false;

    cnt++;
    int x = sum/2;
    int y = sum - x;

    if(cnt>n) return false;

    int pos=1;

    if(!check(x)) pos=0;
    if(!check(y)) pos=0;

    return pos;
}

void solve()
{
    cin>>n;
    mp.clear();
    cnt=0;

    int sum=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        sum+=x;
        mp[x]++;
    }

    if(check(sum)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}