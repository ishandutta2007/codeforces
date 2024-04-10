#include <iostream>
#include <math.h>
#include <map>
using namespace std;
string s1,s2,s3;map<char,int> a1,a2;bool iseq=true;
int main()
{
    cin>>s1>>s2>>s3;
for(int i=0;i<s1.size();i++)a1[s1[i]]++;
for(int i=0;i<s2.size();i++)a1[s2[i]]++;
for(int i=0;i<s3.size();i++)a2[s3[i]]++;
for(char i='A';i<='Z';i++)if(a1[i]!=a2[i])iseq=false;
if(iseq)cout<<"YES";
else cout<<"NO";
    return 0;
}