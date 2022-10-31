// Hydro submission #6253c20f48f7830132791ac0@1649656336094
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;int t=0,i;
    cin>>s;
    for(i=1;i<s.size();i++)
    if(s[i]>=65&&s[i]<=90)
    t++;if(t==s.size()-1)
    for(i=0;i<s.size();i++)
    if(s[i]>=97&&s[i]<=122)
    s[i]=toupper(s[i]);
    else s[i]=tolower(s[i]);
    cout<<s<<endl;
    return 0;
}