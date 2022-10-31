// Hydro submission #6253c5afca53060146715ee3@1649657264843
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;int mx,i,t=0;cin>>s;
    for(i=0;i<s.size();i++)
    if(s[i]>mx) mx=s[i];
    for(i=0;i<s.size();i++)
    if(s[i]==mx) t++;
    for(i=0;i<t;i++)
    printf("%c",mx);
    cout<<endl;
    return 0;
}