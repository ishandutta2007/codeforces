#include <bits/stdc++.h>
using namespace std;
map<string,bool> a;
int main()
{
int n;
string s;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>s;
if(a[s]){cout<<"YES"<<endl;continue;}
cout<<"NO"<<endl;
a[s]=true;


}
return 0;}