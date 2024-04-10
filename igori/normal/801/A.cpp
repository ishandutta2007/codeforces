#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans=0;
    int now=0;
    for(int j=0; j<s.size()-1; j++)
            {
                if((s[j]=='V')&&(s[j+1]=='K'))
                    now++;
            }
    if(now>ans)
            ans=now;
    for(int i=0; i<s.size(); i++)
    {
        now=0;
        if(s[i]=='V')
        {
            s[i]='K';
            for(int j=0; j<s.size()-1; j++)
            {
                if((s[j]=='V')&&(s[j+1]=='K'))
                    now++;
            }
            s[i]='V';
        }
        if(s[i]=='K')
        {
            s[i]='V';
            for(int j=0; j<s.size()-1; j++)
            {
                if((s[j]=='V')&&(s[j+1]=='K'))
                    now++;
            }
            s[i]='K';
        }
        if(now>ans)
            ans=now;

    }
    cout<<ans;

}