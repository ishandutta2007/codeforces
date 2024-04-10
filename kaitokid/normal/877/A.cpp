#include <bits/stdc++.h> 
using namespace std ;
int ans;
int main()
{ios::sync_with_stdio(0);
string s;
cin>>s;
string a=s;
for(int i=0;i<a.size();i++)
{
if
(a.size()-i>=5&&s[i]=='D'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='i'&&s[i+4]=='l')ans++;
if
(a.size()-i>=4&&s[i]=='O'&&s[i+1]=='l'&&s[i+2]=='y'&&s[i+3]=='a')ans++;
if
(a.size()-i>=5&&s[i]=='S'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='a')ans++;
if
(a.size()-i>=3&&s[i]=='A'&&s[i+1]=='n'&&s[i+2]=='n')ans++;

if
(a.size()-i>=6&&s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='k'&&s[i+3]=='i'&&s[i+4]=='t'&&s[i+5]=='a')ans++;
if(ans>1){cout<<"No";return 0;}

}
if(ans==1)cout<<"Yes";else
cout<<"No";

return 0;}