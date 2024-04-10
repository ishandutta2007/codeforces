#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char s[1002], c[1002];
int v[30], v1[30];

int main()
{

    cin>>s;
    cin>>c;
    char a='a', *p;
    while(a<='z')
    {
        p=strchr(s, a);
        while(p)
        v[a-'a']++, p=strchr(p+1, a);
        a++;
    }
    a='a';
        while(a<='z')
    {
        p=strchr(c, a);
        while(p)
       v1[a-'a']++, p=strchr(p+1, a);
       a++;
    }
    int rez=0;
    for(int i=0;i<=25;i++)
        rez+=min(v[i], v1[i]);
        int lg=strlen(c);
        for(int i=0;i<lg;i++)
            if(v[c[i]-'a']==0)
        {cout<<-1; return 0;}
cout<<rez;

    return 0;
}