#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string.h>
#define M_PI        3.14159265358979323846
using namespace std;
long xx1,yy1,xx2,yy2,n,ans;
int main()
{//freopen("race.in","r",stdin);freopen("race.out","w",stdout);
cin>>n>>xx1>>yy1>>xx2>>yy2;
if ((xx1==0&&xx2==n)||(xx1==n&&xx2==0))
ans=min(n+yy1+yy2,n+n-yy2+n-yy1);
else {if
((yy1==0&&yy2==n)||(yy1==n&&yy2==0))
ans=min(n+xx1+xx2,n+n-xx2+n-xx1);
else ans=abs(xx1-xx2)+abs(yy1-yy2);}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}