// Hydro submission #626779da9f31360077e12ae0@1650948570443
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,l,b,e,m;
    string s;bool f;
    cin>>t;
    for(i=0;i<t;i++)
    {
        f=false;
        cin>>s;m=0;
        l=s.size();
        b=0,e=l-1;
        for(j=0;j<l;j++)
        if(s[j]==49)
        {
            b=j;
            f=true;
            break;
        }
        for(j=l-1;j+1;j--)
        if(s[j]==49)
        {
            e=j;
            f=true;
            break;
        }
        for(j=b;j<=e;j++)
        if(s[j]==48) m++;
        printf("%d\n",f?m:0);
    }
    return 0;
}