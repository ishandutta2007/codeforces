#include<bits/stdc++.h>
using namespace std;
string ans="z";
int k;
int main()
{
cin>>k;
int num=0;
int i ='z';
int r=0;
int l=1;
while(r!=k)
{
r+=l;
ans+=char(i);
l++;
if(r+l>k){i--;l=0;}

}
if(i!='a')ans+='a';
cout<<ans;
return 0;
}