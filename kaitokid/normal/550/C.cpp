#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
ios::sync_with_stdio(0);

cin>>s;

for(int i=0;i<s.size();i++)
{
if((s[i]-'0')%8==0){ cout<<"YES\n"<<s[i];return 0;}
for(int j=i+1;j<s.size();j++)
{

if(((s[i]-'0')*10+(s[j]-'0'))%8==0){ cout<<"YES\n"<<s[i]<<s[j];return 0;}
for(int z=j+1;z<s.size();z++){
if(((s[i]-'0')*100+(s[j]-'0')*10+(s[z]-'0'))%8==0){ cout<<"YES\n"<<s[i]<<s[j]<<s[z];return 0;}
}

}




}
cout<<"NO";
return 0;}