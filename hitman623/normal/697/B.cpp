#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[500];
    int m,i,b,j,f=0;
    cin>>a;
    m=strlen(a);
    a[m+1]=0;
    for(i=0;i<m;++i)
    {
        if(a[i]=='e')
        {
           if(a[i+3]==0)
           {
               if(a[i+2]==0)
                b=a[i+1]-'0';
               else b=(a[i+1]-'0')*10+a[i+2]-'0';
           }
           else b=(a[i+1]-'0')*100+(a[i+2]-'0')*10+a[i+3]-'0';
        }
    }
    for(i=0;i<m;++i)
    {
        if(a[i]=='.')
            {for(j=i;a[j]!='e';++j)
            a[j]=a[j+1];
        a[j-1]=0;
        m=strlen(a);break;}
    }
    for(i=0;i<m;++i)
        if(a[i]!='0') goto d;
        cout<<0;exit(0);
    d:
    for(i=b+1;i<m;++i)
        if(a[i]!='0') goto l;
    if(b+1<m)
    {a[b+1]=0;
    m=b+1;}
    l:
    for(i=0;i<m;++i)
    {
        if(i<=b)
            {
                if(f==0 && a[i]=='0');
                else
                {cout<<a[i];f=1;}
            }
        else if(i==b+1)
        {
            if(f==0) cout<<'0';
            cout<<"."<<a[i];
        }
        else cout<<a[i];
    }
    //cout<<b;
    for(;i<=b;++i)
        cout<<'0';
    return 0;
}