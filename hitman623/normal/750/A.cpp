#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s=0,n,k,t,i;
    cin>>n>>k;
    t=240-k;
    for(i=1;i<30;++i)
      {
        s+=5*i;
     if(s>t) {if(i-1<=n)cout<<i-1;else cout<<n;exit(0);}
      }
    return 0;
}