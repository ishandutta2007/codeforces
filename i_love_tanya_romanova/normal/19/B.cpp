#include <iostream>
#include <math.h>
using namespace std;
long long n,t[2200],c[2200],ans[2200][2200];
int main(){
cin>>n;
for (int i=1;i<=n;i++){cin>>t[i]>>c[i];++t[i];}

for (int i=0;i<=n;i++)
for (int j=0;j<=n;j++)
ans[i][j]=1000000000000000ll;

ans[0][0]=0;

for (int i=0;i<n;i++)
for (int j=n;j+1;j--)
{
    ans[i+1][j]=min(ans[i][j],ans[i+1][j]);
    ans[i+1][min(n,j+t[i+1])]=min(ans[i+1][min(n,j+t[i+1])],ans[i][j]+c[i+1]);
}

cout<<ans[n][n]<<endl;

cin.get();cin.get();
return 0;}