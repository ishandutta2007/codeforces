#include <bits/stdc++.h>

using namespace std;

int fr[400];
string s;
int sum;
vector <int > v;
string sol;
/*
string solve(int pr, int ul)
{
    for(int i=pr;i<=ul;i++)
    {
        if(s[i]=='?')
            v.push_back(i);
    }
    for(int i='A';i<='Z';i++)
    {
        if(fr[i]==0)
            s[v.back()]=char(i),
            v.pop_back();
    }
    return s.substr(pr, 26);
}
*/
bool solve(string s)
{
    int fre[259];
    for(int i=0;i<256;i++)
        fre[i]=0;
    for(int i=0;i<26;i++)
    {
        if(fre[s[i]]==1)
            return 0;

        if(s[i]=='?')
            v.push_back(i);\
            else fre[s[i]]++;
    }
    for(int i='A';i<='Z';i++)
    {
        if(fre[i]==0)
            s[v.back()]=char(i),
            v.pop_back();
    }
    sol=s;
    return 1;
}

int main()
{
cin>>s;

if(s.size()<26)
{
    cout<<-1<<'\n';
    return 0;
}

for(int i=0;i<=s.size()-26;i++)
{
    if(solve(s.substr(i, 26)))
    {
        for(int k=0;k<26;k++)
        {
            s[i+k]=sol[k];
        }
        for(int i=0;i<s.size();i++)
            if(s[i]=='?') s[i]='A';
        cout<<s<<'\n';
        return 0;
    }

}

cout<<"-1\n";
/*
for(int i=0;i<26;i++)
{
    fr[s[i]]++;
    if(fr[s[i]]==1 && s[i]!='?')
        sum++;
}
int i=0, j=26;

if(sum+fr['?']==26)
    {
        cout<<solve(0, 25);
        return 0;
    }

while(j<s.size())
{
    fr[s[i]]--;
    if(fr[s[i]]==0) sum--;
    fr[s[j]]++;
    if(fr[s[j]]==1) sum++;

    if(sum+fr['?']==26)
    {
        cout<<solve(i+1, j);
        return 0;
    }
    i++;
    j++;

}
/*
if(sum+fr['?']==26)
    {
        cout<<solve(i+1, j);
        return 0;
    }

cout<<"-1\n";

*/


    return 0;
}