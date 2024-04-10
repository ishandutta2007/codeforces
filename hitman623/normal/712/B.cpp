#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;

int main()
{
    char s[100001];
    cin>>s;
    int i,m=strlen(s),j,l=0,r=0,u=0,d=0,p=0,q,w;
    for(i=0;i<m;++i)
    {
      if(s[i]=='U')u++;
      if(s[i]=='D')d++;
      if(s[i]=='L')l++;
      if(s[i]=='R')r++;
    }
    if(m%2==1) {cout<<-1;goto e;}
    q=fabs(u-d);
    w=fabs(l-r);
        p+=q/2;
        p+=w/2;
    if(q%2==1)
        p+=1;
    cout<<p;
    e:
    return 0;
}