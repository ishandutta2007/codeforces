#include <bits/stdc++.h>

using namespace std;
vector<int> a;
int main()

{string s;
cin>>s;
int ans=0;
for(int i=1;i<=s.size();i++)
{
    ans+=pow(2,i);

  if(s[i-1]=='7'){a.push_back(s.size()-i);}
}
ans-=pow(2,s.size())-1;

for(int i=0;i<a.size();i++)
{
    ans+=pow(2,a[i]);
}
cout<<ans;
    return 0;
}