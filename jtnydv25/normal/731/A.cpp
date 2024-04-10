#include <bits/stdc++.h>
using namespace std;

inline int dist(char x, char y)
{
    if(x>y)
        swap(x,y);
    return min(y-x,x-y + 26);
}
int main()
{
    string s;
    cin>>s;
    char now = 'a';
    int ans = 0;
    for(int i = 0;i<s.length();i++)
    {
        ans+=dist(s[i],now);
        now = s[i];
    }
    cout<<ans;
}