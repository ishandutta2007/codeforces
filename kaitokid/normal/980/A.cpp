#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
ios::sync_with_stdio(0);
string s;
cin>>s;
for(int i=0;i<s.size();i++)
if(s[i]=='-')a++;else b++;
if(b==1||a%(b)==0||a==0||b==0)cout<<"YES";
else cout<<"NO";
}