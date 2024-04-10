#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,c=0,d=0,an=1000000007,e[100000]={0},j=0,b[100000]={0};
    char a[100001];
    cin>>n>>a;
    for(i=0;i<n;++i)
        {e[a[i]]++;if(e[a[i]]==1) d++;}
    for(i=0;i<n;++i)
    {
      b[a[i]]++;
      if(b[a[i]]==1) c++;
      while(b[a[j]]>1)
      {
          b[a[j]]--;j++;
      }
      if(c==d) an=min(an,i-j+1);
    }
    cout<<an;
    return 0;
}