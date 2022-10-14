#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool str[27];int cnt;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    if(!str[s[i]-'a'])cnt++,str[s[i]-'a']=true;
    if(cnt%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";



    return 0;
}