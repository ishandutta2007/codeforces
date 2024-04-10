#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll n;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        ll d=0,r=0;
        for(int i=0;i<s.size();i++)if(s[i]=='R')r++;else d++;
        if(d==0 || r==0){cout<<n<<endl;continue;}
        ll ans=(n-d)*(n-r)+1;
        bool br=false,bd=false;
        for(int i=0;i+1<s.size();i++)
        {
            if(s[i]=='R')br=true;
            if(s[i]=='D')bd=true;
            ans++;
            if(s[i+1]=='D' &&(br))ans+=n-r-1;
            if(s[i+1]=='R' &&(bd))ans+=n-d-1;

        }
        cout<<ans<<endl;
        }
    return 0;
}