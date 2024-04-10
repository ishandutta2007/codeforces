#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
ll cnt;
int main()
{
    cin>>str;
    while(str[0]=='0')
    {
        str.erase(0,1);
    }
    for(register int i=0;i<str.length();i++)
    {
        if(str[i]=='0')
        {
            cnt++;
        }
    }
    cnt>=6?cout<<"yes"<<endl:cout<<"no"<<endl;
}