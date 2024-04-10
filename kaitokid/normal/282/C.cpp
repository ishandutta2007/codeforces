#include<bits/stdc++.h>
using namespace std;

int main()
{ios::sync_with_stdio(0);

string a,b;
cin>>a>>b;
if(a.size()!=b.size()){cout<<"NO";return 0;}
if(a==b){cout<<"YES";return 0;}
bool bl1=false,bl2=false;
for(int i=0;i<a.size();i++)
{
if(a[i]=='1')bl1=true;
if(b[i]=='1')bl2=true;

}
if(bl1&&bl2){cout<<"YES";return 0;}
cout<<"NO";
 return 0;
}