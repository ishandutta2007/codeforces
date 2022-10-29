#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1000001],s[1000001];
    long i,m,p=-1,e=0,f=1,pp=1,z=0,o=0;
    cin>>a;
    m=strlen(a);
    for(i=0;i<m;++i)
    {
        if(a[i]!='0' && f==1) { f=0;if(a[i]=='.') {pp=0;e--;p=0;}else {p=a[i]-'0';}}
        else if(p!=-1)
        {
            if(pp==0)
            {
                if(a[i]=='0' && p==0) e--;
                else if(p==0) p=a[i]-'0';
                else {s[o++]=a[i];}
            }
            else
            {
             if(a[i]=='.' && pp==1) {pp=2;}
             else if(pp!=2) {e++;s[o++]=a[i];}
             else {s[o++]=a[i];}
            }
        }
    }
    --o;
    while(s[o]=='0'){--o;}
    s[o+1]='\0';
    cout<<p;
    if(o!=-1)
    {   cout<<'.';
     cout<<s;
    }
    else {if(p==0)e=0;}
    if(e!=0) cout<<'E'<<e;
    return 0;
}