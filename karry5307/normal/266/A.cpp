#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
ll len,num;
int main()
{
    cin>>len>>str;
    for(register int i=1;i<str.length();i++)
    {
        if(str[i]==str[i-1])
        {
            num++;
        }
    }
    cout<<num;
}