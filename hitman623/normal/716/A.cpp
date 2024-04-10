#include <iostream>

using namespace std;

int main()
{
   long long n,c,i,a=0,b[100001]={0};
   cin>>n>>c;
   for(i=0;i<n;i++)
    {cin>>b[i];
     if(b[i]-b[i-1]>c && i!=0) a=1;
       else a++;
    }
    cout<<a;
    return 0;
}