#include <bits/stdc++.h>

using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
//cin>>n>>m;
for(int i=1;i<=n/2;i++)
    for(int j=1;j<=m;j++)
        printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
//cout<<i<<" "<<j<<endl<<n-i+1<<" "<<m-j+1<<endl;
if(n%2==0)return 0;
for(int i=1;i<=m/2;i++)
    printf("%d %d\n%d %d\n",n/2+1,i,n/2+1,m-i+1);
    //cout<<n/2+1<<" "<<i<<endl<<n/2+1<<" "<<m-i+1<<endl;
if(m%2==0)return 0;
printf("%d %d",n/2+1,m/2+1);
//cout<<n/2+1<<" "<<m/2+1;

    return 0;
}