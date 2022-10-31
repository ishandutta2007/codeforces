// Hydro submission #6247fb3b0bc575b66aa58a84@1648884539324
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;int i,sS=0,ss=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    if(s[i]>=65&&s[i]<=90) sS++;
    else if(s[i]>=97&&s[i]<=122) ss++;
    if(sS>ss) for(i=0;i<s.size();i++) s[i]=toupper(s[i]);
    else for(i=0;i<s.size();i++) s[i]=tolower(s[i]);
    cout<<s<<endl;
    return 0;
}