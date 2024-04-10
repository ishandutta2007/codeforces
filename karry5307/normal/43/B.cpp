#include<bits/stdc++.h>
using namespace std;
typedef int ll;
map<char,ll>mp;
string text,pattern;
int main()
{
    getline(cin,text);
    getline(cin,pattern);
    for(register int i=0;i<text.length();i++)
    {
        if(text[i]!=' ')
        {
            mp[text[i]]++;
        }
    }
    for(register int i=0;i<pattern.length();i++)
    {
        if(pattern[i]!=' ')
        {
            if(mp[pattern[i]]==0)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                mp[pattern[i]]--;
            }
        }
    }
    cout<<"YES"<<endl;
}