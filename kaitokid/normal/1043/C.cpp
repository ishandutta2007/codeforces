#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool bl[1009];
int main()
{ios::sync_with_stdio(0);
string s;
cin>>s;
for(int i=0;i+1<s.size();i++)
    if(s[i]!=s[i+1])bl[i]=true;
if(s[s.size()-1]=='a')bl[s.size()-1]=true;
for(int i=0;i<s.size();i++)cout<<bl[i]<<" ";
   return 0;
}