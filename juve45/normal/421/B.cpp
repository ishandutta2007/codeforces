#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char chr[]="AHIMOTUVWXY";
inline bool valid(char c)
{
for(int i=0;i<=10;i++)
if(c==chr[i]) return true;
return false;
    }

int main()
{
    //freopen("in.txt", "r", stdin);
    char s[100003];
    scanf("%s",&s);
    int lg=strlen(s);
    int ok=0;
    for(int i=0; i<(lg+1)/2; i++)
    {
        if(valid(s[i]))
         {

         if(s[i]!=s[lg-1-i])
           ok=1;
         }    else ok=1;

    }
    if(ok==0)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}