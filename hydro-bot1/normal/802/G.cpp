// Hydro submission #62590cc2cc64917dc46644a5@1650003139225
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int t=0,i;
    for(i=0;i<s.size();i++)
    {
        if(t==0&&s[i]=='h'
        ||t==1&&s[i]=='e'
        ||t==2&&s[i]=='i'
        ||t==3&&s[i]=='d'
        ||t==4&&s[i]=='i')
        t++;
    }
    if(t==5) printf("YES\n");
    else printf("NO\n");
    return 0;
}