#include <bits/stdc++.h>

using namespace std;
int x[16],a;
int n,k,num,lo,s;
int main()
{
      cin>>n>>k;lo=k-1;
      while(lo>=0){num+=pow(2,lo);lo--;}
      for(int i=0;i<n;i++)
        {s=0;for(int j=0;j<k;j++){cin>>a;if(a)s+=pow(2,j);}
            x[s]++;}
      for(int i=0;i<16;i++)if(x[i]){for(int j=i+1;j<16;j++)if(((i&j)==0&&x[j])||x[0]>1||(x[0]==1&&n==1))return cout<<"Yes",0;}
      cout<<"No";

    return 0;
}