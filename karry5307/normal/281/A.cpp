#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
inline void capital(string &str)
{
    str=(char)(toupper(str[0]))+str.substr(1);
}
int main()
{
    cin>>str;
    capital(str);
    cout<<str;
}