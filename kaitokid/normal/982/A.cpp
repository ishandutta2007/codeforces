#include <iostream>

using namespace std;

int main()
{int n;
string s;
cin>>n>>s;
int d=0;
if(n==1&&s[0]=='1'){cout<<"Yes";
    return 0;}
    if(n==1&&s[0]=='0'){cout<<"No";
    return 0;}
if(s[0]=='0')d++;
//if(n%2==1&&s[0]!='1'){cout<<"No";return 0;}

for(int i=1;i<n;i++){if(s[i]=='1'&&s[i-1]=='1'){cout<<"No";return 0;}
if(s[i]=='0'&&s[i+1]=='0'&&s[i-1]=='0')
{cout<<"No";return 0;}}
if(s[0]=='0'&&s[1]=='0'){cout<<"No";return 0;}
if(s[n-1]=='0'&&s[n-2]=='0'){cout<<"No";return 0;}
cout<<"Yes";
    return 0;
}