#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char s[120];
int n;

bool solve(char* str)
{
    int j=0;
    int l=strlen(str);
    for(int i=0;i<n;i++)
        if(s[i]==str[j])
        {
            j++;
            if(j==l)
            {
                cout<<"YES\n"<<str;
                return true;
            }
        }

return false;
}

int main()
{
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='0' || s[i]=='8')
        {
        cout<<"YES\n"<<s[i];
        return 0;
        }



    for(int i=2;i*8<1000;++i)
    {
        char ss[4];
        sprintf(ss,"%d", i*8);
        //cout<<ss<<'\n';

    int l=strlen(ss);
    for(int k=0;k<l;k++)
        if(ss[k]=='0' || ss[k]=='8')
        continue;

    if(solve(ss))
        return 0;
    }
        cout<<"NO\n";

     return 0;
}