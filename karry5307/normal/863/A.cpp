#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
inline void clearSuffix(string &str)
{
    while(str[str.length()-1]=='0')
    {
        str.erase(str.length()-1);
    }
}
inline bool ispal(string str)
{
    for(register int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[str.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
inline void outCF(bool condition)
{
    condition?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
int main()
{
    cin>>str;
    clearSuffix(str);
    outCF(ispal(str));
}