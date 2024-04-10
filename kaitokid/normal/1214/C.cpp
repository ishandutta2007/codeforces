#include <iostream>

using namespace std;
int n,d;
string s;
int main()
{
  ios::sync_with_stdio(0);
cin>>n>>s;
for(int i=0;i<n;i++)
    {if(s[i]=='(')d++;
else d--;
if(d<-1){cout<<"No"; return 0;}}
if(d==0)cout<<"Yes";
else cout<<"No";
    return 0;
}