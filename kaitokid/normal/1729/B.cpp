#include<bits/stdc++.h>
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
    int n;
    string s;
    cin>>n>>s;
    string ans="";
    int i=n-1;
    while(i>=0){
    int u=s[i]-'0';
    if(u!=0){ans+=char('a'+u-1);i--;continue;}
    int z=s[i-2]-'0';
    z*=10;
    z+=s[i-1]-'0';
    ans+=char('a'+z-1);
    i-=3;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    }
    return 0;
}