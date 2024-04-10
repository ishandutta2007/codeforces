/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+1;
string s[N];
int n;

int check(char x)
{
    int dif[n+1];
    int cntr=0;
    for(int i=1; i<=n; i++)
    {
        string a = s[i];
        int cnt=0;
        for(auto y: a)
        {
            if(y==x) cnt++;
            else cnt--;
        }
        dif[++cntr]=cnt;
    }
    sort(dif+1, dif+n+1);
    int len = 0, tot=0;
    for(int i=n; i>=1; i--)
    {
        tot+=dif[i];
        if(tot<=0) break;
        //cout<<i<<" "<<len<<endl;
        len++;
    }
    return len;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++) cin>>s[i];

    int ans = 0;
    for(int i=1; i<=5; i++)
    {
        char x = 'a'+i-1;
        int tmp = check(x);
        ans = max(ans, tmp);
        //cout<<x<<" "<<tmp<<endl;
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