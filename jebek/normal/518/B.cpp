#include <iostream>
#include<string>
#include<map>

using namespace std;

string s,t;
int ans,ans1;
bool mark[300000];
map<char,int>m;

int main()
{
    cin>>s>>t;
    for(int i=0;i<t.size();i++)
        m[t[i]]++;
    for(int i=0;i<s.size();i++)
        if(m[s[i]])
        {
            m[s[i]]--;
            ans++;
            mark[i]=true;
        }
    for(int i=0;i<s.size();i++)
        if(!mark[i])
        {
            if(isupper(s[i]))
            {
                char c=char('a'+int(s[i]-'A'));
                if(m[c])
                {
                    m[c]--;
                    ans1++;
                }
            }
            else
            {
                char c=char('A'+int(s[i]-'a'));
                if(m[c])
                {
                    m[c]--;
                    ans1++;
                }
            }
        }
    cout<<ans<<" "<<ans1<<endl;
}