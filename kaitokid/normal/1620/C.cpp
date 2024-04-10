#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;
        x--;
        string s;
        cin>>s;
        string ans="";
        reverse(s.begin(),s.end());
        int i=0;
        while(i<n)
        {
            if(s[i]=='a'){ans+='a';i++;continue;}
            ll d=0;
            while(i<n && s[i]=='*'){d+=k;i++;}
            for(int j=0;j<(x%(d+1));j++)ans+='b';
            x/=(d+1);
        }

       reverse(ans.begin(),ans.end());
       cout<<ans<<endl;
    }
    return 0;
}