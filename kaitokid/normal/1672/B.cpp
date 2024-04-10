#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
int n=s.size();
int sum=0;
bool ans=true;
for(int i=0;i<n;i++)
{
    if(s[i]=='A')sum++;else sum--;
    if(sum<0)ans=false;

}
if(s[n-1]=='A')ans=false;
if(ans)cout<<"YES\n";
else cout<<"NO\n";
}

return 0;
}