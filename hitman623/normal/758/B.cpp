#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

int main()
{
    char a[200];
    int i,r,g,b,y,c[100],n,j;
    c['G']=-1;
    c['Y']=-1;
    c['R']=-1;
    c['B']=-1;
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;i++)
    {
      if(c[a[i]]==-1)
      {
          c[a[i]]=0;
          for(j=i+4;j<n;j+=4)
            if(a[j]!=a[i]) c[a[i]]++;
          for(j=i-4;j>=0;j-=4)
            if(a[j]!=a[i]) c[a[i]]++;
      }
    }
 cout<<c['R']<<" "<<c['B']<<" "<<c['Y']<<" "<<c['G'];
    return 0;
}