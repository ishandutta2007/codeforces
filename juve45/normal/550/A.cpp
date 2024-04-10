#include <bits/stdc++.h>

using namespace std;

char s[100005];

int main()
{
    cin>>s;
    int n=strlen(s);
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B')
        {
            for(int j=i+2;j<n-1;j++)
            {
                if(s[j]=='B' && s[j+1]=='A')
                {
                    cout<<"YES\n";
                    return 0;
                }

            }
            break;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='B'&&s[i+1]=='A')
        {
            for(int j=i+2;j<n-1;j++)
            {
                if(s[j]=='A' && s[j+1]=='B')
                {
                    cout<<"YES\n";
                    return 0;
                }

            }
            break;
        }
    }

    cout<<"NO\n";

    return 0;
}