#include <bits/stdc++.h>
using namespace std ;
int l,d;
int main(){
ios::sync_with_stdio(0);
string s;
int n;
cin>>n>>s;
for(int i=0;i<n-1;i++)
{
if(s[i]=='S'&&s[i+1]=='F')l++;

if(s[i]=='F'&&s[i+1]=='S')d++;

}
if(l>d){cout<<"YES";return 0;}
cout<<"NO";
 return 0;}