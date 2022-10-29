#include <iostream>

using namespace std;

int main()
{
   long long a,b,i=0,x[200];
    cin>>a>>b;
    while(b>a)
   {   x[i]=b;
       if((b-1)%10==0)
       {
         b=(b-1)/10;
       }
       else if(b%2==0) b/=2;
       else break;
     i++;
   }
   if(b==a)
   {
       cout<<"YES"<<endl;
       cout<<i+1<<endl;
        cout<<a<<" ";
       for(int j=0;j<i;++j)
        cout<<x[i-j-1]<<" ";
   }
   else cout<<"NO";
    return 0;
}