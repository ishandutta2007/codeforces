/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int Infy = 1e6;

int rep(string s, char x)
{
    int n = s.size();
    int j = n-1;
    int lst=-1;

    vector<int> gap;
    for(int i=0; i<n; i++)
    {
        if(s[i]==x) continue;
        gap.push_back(i-lst-1);
        lst=i;

        while(s[j]==x) j--;
        if(s[i]!=s[j]) return Infy;
        j--;
    }
    gap.push_back(n-lst-1);

    //cout<<s<<endl;
    //cout<<x<<endl;
    //for(int x: gap) cout<<x<<" ";
    //cout<<endl;

    int m = gap.size(), ans=0;
    for(int i=0; 2*i<m; i++)
    {
        int x = gap[i];
        int y = gap[m-i-1];
        ans+=abs(x-y);
    }
    //cout<<ans<<endl;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans = Infy;
    for(char x='a'; x<='z'; x++)
    {
        int tmp = rep(s, x);
        ans = min(tmp, ans);
    }

    if(ans>n) ans=-1;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}