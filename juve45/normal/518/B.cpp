#include <bits/stdc++.h>
#define DMAX 200005
using namespace std;

string s, t;
map <char, int> m;
int use[DMAX];
int main()
{
cin>>s>>t;
int y=0, w=0;

for(int i=0;i<t.size();++i)
{
    if(m.find(t[i])==m.end())
        m[t[i]]=1;
    else
    m[t[i]]++;
}

for(int i=0;i<s.size();++i)
{
    if(m.find(s[i])!=m.end())
        if(m[s[i]]>0)
        m[s[i]]--, y++, use[i]=1;
}

for(int i=0;i<s.size();++i)
{
    {
        char c;
        if(islower(s[i])) c=toupper(s[i]);
        else c=tolower(s[i]);

    if(m.find(c)!=m.end())
        if(m[c]>0 && !use[i])
        m[c]--, w++;
    }
}

cout<<y<<' '<<w<<'\n';

    return 0;
}