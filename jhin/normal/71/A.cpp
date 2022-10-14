#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
int n,x,sum;string s[101];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){x=s[i].size();
    if(x>10)cout<<s[i][0]<<x-2<<s[i][x-1]<<endl;
   else    cout<<s[i]<<endl;}
    return 0;
}