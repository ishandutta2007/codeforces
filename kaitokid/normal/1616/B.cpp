#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[300];
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
    if(n==1){cout<<s<<s<<endl;continue;}
    if(s[1]>=s[0]){cout<<s[0]<<s[0]<<endl;continue;}
    string ans="";
    ans+=s[0];
    for(int i=1;i<n;i++)if(s[i]>s[i-1])break;else ans+=s[i];
    cout<<ans;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


    }

    return 0;
}