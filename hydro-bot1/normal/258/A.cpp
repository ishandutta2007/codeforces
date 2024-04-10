// Hydro submission #6297580a1008115bd64b727d@1654085642819
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.size(),i;
    for(i=0;i<l;i++)
    if(s[i]==48||i==l-1)
    {
        s.erase(i,1);
        break;
    }
    cout<<s<<endl;
    return 0;
}