#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long ans,n,m,a,b,ax,ay,bx,by;
int main(){
    cin>>n>>m>>a>>b;
    --a;--b;
    ans=3;
    ax=a/m;ay=a%m;
    bx=b/m;by=b%m;long on=1;
    if (b==n-1)by=m-1;
    long dv=2;
    if (ay==0&&b==n-1)ans=min(ans,on);
    if (bx-ax<2)ans=min(ans,dv);
    if (ay==0&&by==m-1)ans=min(ans,on);
    if (m==1)ans=min(ans,on);
    if (ax==bx)ans=min(ans,on);
    if (ay==0||by==m-1)ans=min(ans,dv);
    if (ay-by==1)ans=min(ans,dv);
    cout<<ans<<endl;
    
cin.get();cin.get();
return 0;
}