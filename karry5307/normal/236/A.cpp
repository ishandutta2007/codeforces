#include<bits/stdc++.h>
using namespace std;
typedef int ll;
map<char,ll>mp;
string str;
int main()
{
    cin>>str;
    for(register int i=0;i<str.length();i++)
    {
        mp[str[i]]++;
    }
    mp.size()%2==0?cout<<"CHAT WITH HER!"<<endl:cout<<"IGNORE HIM!"<<endl;
}