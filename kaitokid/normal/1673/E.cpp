#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,b[(1<<20)+2];
int c[26][(1<<20)+2];
int ch(int x,int y)
{
    if(x<y)return 0;
    int g=0;
    for(int i=0;i<21;i++)
       {

        g+=x/(1<<i);
        g-=y/(1<<i);
       g-=(x-y)/(1<<i);}
    return (g==0);

}
bool go(int x,int y)
{

    if(y>x)return 0;
    int h=c[n-x][x];
    if(y>0)h=(h-c[n-x][y-1]+2)%2;
   // cout<<x<<" "<<y<<" "<<c[n-x][x]<<" "<<h<<endl;
    return h;
}
int main()
{
    scanf("%d%d",&n,&k);
       for(int j=0;j<=n;j++)
       c[min(25,n)][j]=ch(n-min(25,n),j);
       for(int i=min(n-1,24);i>=0;i--)
       {
        c[i][0]=1;
        for(int j=1;j<=n;j++)
       c[i][j]=(c[i+1][j-1]+c[i+1][j])%2;
       }
      for(int i=0;i<25;i++)
        for(int j=1;j<=n;j++)
        c[i][j]=(c[i][j]+c[i][j-1])%2;
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    vector<int>ans((1<<20),0);
    for(int i=0;i<n;i++)
    {
        ll r=b[i];
        int v=0;
        if(i>0)v++;
        if(i<n-1)v++;
       // cout<<n-1-v<<" "<<v<<" "<<r<<endl;
        if(go(n-1-v,k-v))ans[r]=1-ans[r];
        int j=i+1;
        while(j<n)
        {
            if(b[j]>20)break;

            r*=(1<<b[j]);
            if(r>=(1<<20))break;
            int v=0;
            if(i>0)v++;
            if(j<n-1)v++;

          // cout<<n-1-v-(j-i)<<" "<<v<<" "<<r<<endl;
            if(go(n-1-v-(j-i),k-v))ans[r]=1-ans[r];
            j++;

        }


    }
    int i=(1<<20)-1;
    while(i>0 && (ans[i]==0))i--;
    for(int j=i;j>=0;j--)printf("%d",ans[j]);
    return 0;
}