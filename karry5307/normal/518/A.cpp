#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str,str1;
ll pos;
int main()
{
    cin>>str>>str1;
    if(str>=str1)
    {
        cout<<"No such string"<<endl;
        return 0;
    }
    pos=str.length()-1;
    str[pos]++;
    while(str[pos]=='{')
    {
        str[pos]='a';
        str[--pos]++;
    }
    if(str>=str1)
    {
        cout<<"No such string"<<endl;
        return 0;
    }
    cout<<str;
}