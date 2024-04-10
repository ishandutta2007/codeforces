#include <bits/stdc++.h>

using namespace std;
long long n,m,p,i,o=0,l[500005]={0},r[500005]={0},j,k;
char a[500005],s[500005];
int main()
{
    cin>>n>>m>>p;
    cin>>a;
    cin>>s;
    for(i=0;i<=n;++i)
    {
        l[i]=i-1;
        r[i]=i+1;
    }
    j=p-1;
    for(i=0;i<m;++i)
    {
      switch(s[i])
      {
          case 'L':j=l[j];break;
          case 'R':j=r[j];break;
          case 'D': o=1;
                    if(a[j]=='(')
                        {
                            a[j]='*';
                            for(k=r[j];o!=0;k=r[k])
                             {
                                 if(a[k]=='(') o++;
                                 else o--;
                                 a[k]='*';
                             }
                             r[l[j]]=k;
                             l[k]=l[j];
                             if(r[l[k]]==n)
                                j=l[j];
                             else j=k;
                        }
                    else if(a[j]==')')
                        {
                            a[j]='*';
                            for(k=l[j];o!=0;k=l[k])
                             {
                                 if(a[k]==')') o++;
                                 else o--;
                                 a[k]='*';
                             }
                             l[r[j]]=k;
                             r[k]=r[j];
                             if(r[j]==n) j=k;
                             else
                             j=r[j];
                        }
                        break;
      }
    }
      for(k=0;k<n;++k)
    {
        if(a[k]=='(' || a[k]==')')
            cout<<a[k];
    }
    return 0;
}