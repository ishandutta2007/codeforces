#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t>0)
          {
              long int n,v,strt,nd;
              cin>>n;
              long int a[n];
              for(int i=0;i<n;i++)
              {
                  cin>>v;
                  a[v-1]=i;
              }
              strt=a[0];
              nd=a[0];
              for(int i=0;i<n;i++)
              {
                  strt=min(strt,a[i]);
                  nd=max(nd,a[i]);
                  if(nd-strt==i) cout<<1;
                  else cout<<0;
              }
              cout<<endl;
              t--;
          }
    return 0;
}