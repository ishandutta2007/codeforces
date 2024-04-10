#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

string s,s1,t;

int main()
{
    t="CODEFORCES";
    cin>>s;
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<=s.size();j++)
        {
            s1="";
            for(int k=0;k<i;k++)
                s1+=s[k];
            for(int k=j;k<s.size();k++)
                s1+=s[k];
            if(s1==t)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    cout<<"NO"<<endl;
}