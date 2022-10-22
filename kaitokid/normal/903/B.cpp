#include <bits/stdc++.h>
using namespace std;

map<int,int>a;
int main()
{
ios::sync_with_stdio(0);
int h,a,c,h2,a2;
cin>>h>>a>>c>>h2>>a2;
vector<string>s;
while(h2>0)
{

h2-=a;
h-=a2;
if(h<=0&&h2>0){s.push_back("HEAL");h2+=a;h+=c;continue;}
s.push_back("STRIKE");}

cout<<s.size()<<endl;
for(int i=0;i<s.size();i++)cout<<s[i]<<endl;






return 0;}