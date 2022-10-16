#include <iostream>
#include <cstring>
using namespace std;
char t[5000], *s;
int main()
{
cin>>t;
s=t;
int l=strlen(t);
int lg=strlen(s);
int pr=0;
char *p=strstr(s, "bear");

while(p)
{
    pr=pr+(p-s+1)*(s+lg-p-3);
    s=p+1;
    //lg=strlen(s);
    lg=t+l-s;
    p=strstr(p+1, "bear");

}
cout<<pr;
    return 0;
}