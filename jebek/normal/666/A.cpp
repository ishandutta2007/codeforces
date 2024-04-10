#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

string s,s1;
set<string>se;
bool mark[20000][2];

bool cmp(int i,int j)
{
    if(j>=s.size()) return true;
    if(s[i]!=s[j]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>s;
    mark[s.size()][2]=true;
    mark[s.size()][3]=true;
    for(int i=s.size()-2;i>4;i--)
    {
        s1=s[i];
        s1+=s[i+1];
        if(mark[i+2][3] || (mark[i+2][2] && (cmp(i,i+2) || cmp(i+1,i+3))))
        {
            mark[i][2]=true;
            se.insert(s1);
        }
        if(i<s.size()-2)
            if(mark[i+3][2] || (mark[i+3][3] && (cmp(i,i+3) || cmp(i+1,i+4) || cmp(i+2,i+5))))
            {
                mark[i][3]=true;
                s1+=s[i+2];
                se.insert(s1);
            }
       // cout<<i<<" "<<mark[i][2]<<" "<<mark[i][3]<<endl;
    }
    cout<<se.size()<<endl;
    while(se.size())
    {
        cout<<*(se.begin())<<'\n';
        se.erase(se.begin());
    }
}