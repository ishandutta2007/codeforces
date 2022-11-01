#include <bits\stdc++.h>

using namespace std;
    bool sot[255]={0},sot1[255]={0};
    int a[4]={0},b[4]={0};
int main()
{
    string s;
    cin>>s;

    int ans=0;

    sot1['}']=sot1[']']=sot1[')']=sot1['>']= 1;
    sot['<']=sot['(']= sot['['] = sot['{'] =1;

    int len=s.size();
    bool imp=0;
    int open=0,popened=0,closed=0;

    for (int i=0;i<len;i++)
    {
        if (sot[s[i]])
            {open++;popened++;}
        else
            closed++;
        if (open<closed)
            {
                imp=1;
                break;
            }
    }

    if (open!=closed)
        imp=1;


    if (imp)
    {
        cout<<"Impossible";
    }
    else
    {
        vector<int> news;


        for (int i=0;i<len;i++) {
        if (s[i]=='<'||s[i]=='['||s[i]=='{'||s[i]=='(')
        {
            news.push_back(s[i]);
            continue;
        }

            if((s[i] == '>' && news.back() == '<')||(s[i] == '}' && news.back() == '{')||(s[i] == ']' && news.back() == '[') ||( s[i] == ')' && news.back() == '(') ) ans--;
            ans++;
            news.pop_back();
    }
    cout<<ans;
    }

    return 0;
}