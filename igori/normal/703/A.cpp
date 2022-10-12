#include <iostream>

using namespace std;

int main()
{
      int n;
      int m[100];
      int c[100];
      cin>>n;

      for(int i=0;i<n;i++)
      {
          cin>>m[i];
          cin>>c[i];
      }
      int mc=0;
      int cc=0;
      for(int i=0;i<n;i++)
      {
        if (m[i]>c[i])
        {
            mc=mc+1;
        }
        if (m[i]<c[i])
        {
            cc=cc+1;
        }
      }
      if(mc>cc)
      {
          cout<<"Mishka";
      }
      if(cc>mc)
      {
          cout<<"Chris";
      }
      if(mc==cc)
      {
          cout<<"Friendship is magic!^^";
      }
}