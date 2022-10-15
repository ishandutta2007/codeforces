/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int Infy = 1000;

int make(string a, string b)
{
    int n = a.size();
    int j = b.size()-1;
    int ans=0;
    for(int i=n-1; i>=0; i--)
    {
        if(j==-1) break;
        if(a[i]==b[j]) j--;
        else ans++;
        if(j==-1) break;
    }

    if(j==-1) return ans;
    else return Infy;
}

void solve()
{
    string s;
    cin>>s;

    string d[4] = {"00", "25", "50", "75"};

    int ans = Infy;
    for(int i=0; i<4; i++)
    {
        int tmp = make(s, d[i]);
        ans = min(ans, tmp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}