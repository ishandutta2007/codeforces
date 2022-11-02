#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
ll len,a,d;
int main()
{
    cin>>len>>str;
    for(register int i=0;i<str.length();i++)
    {
        if(str[i]=='A')
        {
            a++;
        }
        else
        {
            d++;
        }
    }
    a==d?cout<<"Friendship"<<endl:a>d?cout<<"Anton"<<endl:cout<<"Danik"<<endl;
}