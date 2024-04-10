#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[20];
    int n,i,m,z=0;
    cin>>a>>n;
    m=strlen(a);
    for(i=m-1;i>=0;--i)
    { if(a[i]=='0') z++;
      if(z>=n) {cout<<m-i-z;return 0;} }
    cout<<m-1;
    return 0;
}