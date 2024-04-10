#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1e9 + 7;
int main()
{
ios::sync_with_stdio(0);
string s;
ll ans=0;
cin>>s;
for(int i=0;i<s.size();i++)
if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='1'
||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')ans++;
cout<<ans;
return 0;}