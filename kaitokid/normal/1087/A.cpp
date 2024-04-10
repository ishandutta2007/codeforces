#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
string s,ans="";
cin>>s;
int i=0,j= s.size()-1;
if(s.size()%2==1){ans+=s[0];i++;}
while(i<=j)
{
if(i==j){ans+=s[i];break;}
ans+=s[j];
ans+=s[i];
i++;j--;

}
reverse(ans.begin(),ans.end());
   cout<<ans;
    return 0;
}