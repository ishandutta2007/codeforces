#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
      string ans="";
      string s;
      int n;
      cin>>n;
      cin>>ans;

      for(int i=3;i<n;i++)
      {
          cin>>s;
          int u=ans.size();
          if(s[0]==ans[u-1])ans+=s[1];
          else ans+=s;
      }
      if(ans.size()<n)ans+='a';
      cout<<ans<<endl;
    }
    return 0;
}