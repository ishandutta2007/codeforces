#include <bits/stdc++.h>

using namespace std;

string s[100005];
int n;
int main()
{
cin>>n;

    for(int i=1;i<=n;i++)
        cin>>s[i];

    int lg=s[1].size();

    char ok;

    for(int i=0;i<lg;i++)
    {
        int skip=0;
        ok='?';
        char ans;
        for(int j=1;j<=n;j++)
        {
            if(ok=='?')
            {if('a'<=s[j][i] && 'z'>=s[j][i])
                ok=s[j][i];
            }
            else if(ok!=s[j][i])
            {
                if(s[j][i]!='?')
                printf("?"),j=n+1, skip=1;
            }
        }
        if(skip!=1)
        {
        if(ok=='?')printf("x");
        else
        printf("%c", ok);
        }
    }

    return 0;
}