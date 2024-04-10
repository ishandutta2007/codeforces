#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t;

 cin>>t;
 while(t--)
 {
 string s;
 cin>>s;
 int ans=0,d=0,h=0;
 for(int i=0;i<s.size();i++)
 {
     if(s[i]=='(')d++;
     if(s[i]=='[')h++;
     if(s[i]==')'&&d>0){d--;ans++;}
     if(s[i]==']'&&h>0){h--;ans++;}
 }
 cout<<ans<<endl;
 }
    return 0;
}