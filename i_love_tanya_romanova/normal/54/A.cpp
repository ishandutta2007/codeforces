#include <math.h>
#include <iostream>
#include <algorithm>
#define M_PI        3.14159265358979323846
using namespace std;
long long n,k,c,i,q,x[100000],ans,dist;
int main()
{//freopen("C:/input.txt","r",stdin);freopen("C:/output.txt","w",stdout);
cin>>n>>k;
cin>>c;
for (i=1;i<=c;i++){cin>>q;x[q]=1;}
for (i=1;i<=n;i++){dist++;if (dist==k||x[i]==1){ans++;dist=0;};}
cout<<ans<<endl;
  cin.get();cin.get();cin.get();
return 0;}