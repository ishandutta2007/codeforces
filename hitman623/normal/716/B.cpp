#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[50001];
    long b[26]={0},p=0,c[26]={0},q=0,j=0,i,f=0;
    cin>>a;
    int m=strlen(a);
    for(i=0;i<=m-26;++i)
    {
        q=0;p=0;
        for(j=i;j<26+i;++j)
        {  if(a[j]!='?')
           b[a[j]-65]=1;
           else {c[q]=j;q++;}
        }
        for(j=0;j<26;++j)
            if(b[j]==1) ++p;
        if(p+q!=26)
        {
             for(j=0;j<26;++j)
             b[j]=0;
        continue;}
          else
          {f=1;
            for(j=0;j<26;++j)
                if(b[j]==0)
                a[c[--q]]=(char)(j+65);
                else b[j]=0;
          }
    }
    for(i=0;i<m;++i)
        if(a[i]=='?') a[i]='A';
    if(f==1)cout<<a;
    else cout<<-1;
    return 0;
}