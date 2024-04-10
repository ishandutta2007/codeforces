#include <iostream>
#include <cstring>
using namespace std;

inline bool check1(char s[])
{
    char *p=s;
    while(*p)
    {
        if('a'<=*p && *p<='z')
            return true;
        p=p+1;
    }
    return false;
}
bool check2(char s[])
{
    char *p=s;
    while(*p)
    {
        if('A'<=*p && *p<='Z')
            return true;
        p=p+1;
    }
    return false;
}
bool check3(char s[])
{
    char *p=s;
    while(*p)
    {
        if('0'<=*p && *p<='9')
            return true;
        p=p+1;
    }
    return false;
}

int main()
{
    char s[1200];
    cin>>s;
    if(strlen(s)>=5)
        if(check1(s))
            if(check2(s))
                if(check3(s))
                {
                    cout<<"Correct";
                    return 0;
                }
    cout<<"Too weak";
    return 0;
}