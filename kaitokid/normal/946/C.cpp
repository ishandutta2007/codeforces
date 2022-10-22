#include <bits/stdc++.h>
 using namespace std;
string s;
char c;
int main(){
ios::sync_with_stdio(0);
cin>>s;
c='a';
for(int i=0;i<s.size();i++)
{
if(s[i]<=c){s[i]=c;c++;}
if(c>'z'){cout<<s;return 0;}


}
if(c>'z'){cout<<s;return 0;}
cout<<-1;
 return 0;}