
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  if((a==0)&&(b==0))
   { cout<<"NO";return 0;
   }
  if((a-b==1)||(a-b==0)||(a-b==-1))
    cout<<"YES";
    else
    cout<<"NO";
  
}