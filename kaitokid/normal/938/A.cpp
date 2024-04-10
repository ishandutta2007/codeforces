#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

ios::sync_with_stdio(0);
 int n;
string s;
cin>>n>>s;
cout<<s[0];
for(int i=1;i<n;i++)
{
if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u'||s[i]=='y')
if(s[i-1]=='a'||s[i-1]=='o'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='u'||s[i-1]=='y')continue;
cout<<s[i];

}

return 0;}