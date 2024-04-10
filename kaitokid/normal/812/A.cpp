#include <iostream>

using namespace std;
bool ac [4];
int main()
{
   bool a[4],b[4],c[4],d[4];
   for(int i=0;i<4;i++)
   {
       cin>>a[i]>>b[i]>>c[i]>>d[i];
       if(a[i]==1){ac[i]=1;if(i!=0)ac[i-1]=1;else ac[3]=1;}
       if(b[i]==1){ac[i]=1;if(i<2)ac[i+2]=1;else ac[i-2]=1;}
       if(c[i]==1){ac[i]=1;if(i!=3)ac[i+1]=1;else ac[0]=1;}

   }
   for(int i=0;i<4;i++){if(ac[i]==1&&d[i]==1){cout<<"YES";return 0;}}
cout<<"NO";
    return 0;
}