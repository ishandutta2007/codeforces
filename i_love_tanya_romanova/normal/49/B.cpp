
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
long a,b,aa,bb,ans,s,ost,q,bs,sz1,sz2;
vector <long> v1,v2;
int main()
{
    cin>>a>>b;
    aa=a;bb=b;
    while (aa){bs=max(bs,aa%10);v1.push_back(aa%10);aa/=10;sz1++;}
 while (bb){bs=max(bs,bb%10);v2.push_back(bb%10);bb/=10;sz2++;}
 for (int i=1;i<=10;i++){v1.push_back(0);v2.push_back(0);}
 ++bs;//cout<<bs<<endl;
    for (long q=bs;q<=1000;q++)
    {s=0;ost=0;
     while (s<sz2||s<sz1||ost)
     {ost=ost+v1[s];ost+=v2[s];//cout<<ost<<" "<<s<<" "<<v1[s]<<" "<<v2[s]<<endl;
      ost/=q;s++;}
    ans=max(ans,s);
    }
    cout<<ans<<endl;
    return 0;
}