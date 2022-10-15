#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int u=0,r=0,l=0,d=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='U')
                u++;
            if(s[i]=='L')
                l++;
            if(s[i]=='R')
                r++;
            if(s[i]=='D')
                d++;
        }
        if(-l<=x&&x<=r&&-d<=y&&y<=u)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}