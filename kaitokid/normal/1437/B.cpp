#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        string s;
   cin>>n>>s;
   int ans[2]={0,0};
   for(int i=1;i<s.size();i++)
   {
   if(s[i]==s[i-1])ans[s[i]-'0']++;
   }
   cout<<max(ans[0],ans[1])<<endl;
    }
    return 0;
}