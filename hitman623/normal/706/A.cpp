#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    double a,b,n,t[1000][3],ans=0,p=0;
    long i;
    cin>>a>>b;
    cin>>n;
    for(i=0;i<n;++i)
     cin>>t[i][0]>>t[i][1]>>t[i][2];
      for(i=0;i<n;++i)
      {
       p=sqrt(pow(t[i][0]-a,2)+pow(t[i][1]-b,2))/t[i][2];
       if(p<ans || ans==0)ans=p;
       if(ans==0) break;
      }
      cout<<setprecision(20)<<ans;
    return 0;
}