#include <bits/stdc++.h>

using namespace std;
const int s=1e6;
int n,i,a,b,c,d,x,cnt1,cnt2, num[s];double check=1;
int my_pow(int x,int y)
{   int num=1;
    for(int i=x;y>0;i*=i,y>>=1)
        if(y&1)num*=i;
    return num;
}
int main()
{
   cin>>a>>b>>c;x=a;
   for(int i=1;i<300;i++){
    d=int(log10(b/x))+1;

a*=my_pow(10,d);if(a/b>=10)a/=10,d--;
   i+=d-1;if(!c&&d>1)return cout<<i-d+1,0;
   d=a/b;
  if(d==c)return cout<<i,0;a-=(d*b);
   }

cout<<-1;

    return 0;
}