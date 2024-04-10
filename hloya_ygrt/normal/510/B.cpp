#include <iostream>

using namespace std;
int ans=0,x=0,n,m,u[51][51];
char c[51][51];
void dfs(int i,int j,int nap)
{

    u[i][j]=1;
   if (i+1!=n)
   {
         if ((u[i+1][j]==0)&&(c[i][j]==c[i+1][j])&&(nap!=4))
             dfs(i+1,j,2); else
         if ((u[i+1][j]==1)&&(c[i][j]==c[i+1][j])&&(nap!=4))
         {
             ans=1;
             return;
         }
   }
     if (j+1!=m)
   {
         if ((u[i][j+1]==0)&&(c[i][j]==c[i][j+1])&&(nap!=1))
             dfs(i,j+1,3); else
         if ((u[i][j+1]==1)&&(c[i][j]==c[i][j+1])&&(nap!=1))
         {
             ans=1;
             return;
         }
   }
     if (i!=0)
   {
         if ((u[i-1][j]==0)&&(c[i][j]==c[i-1][j])&&(nap!=2))
             dfs(i-1,j,4); else
         if ((u[i-1][j]==1)&&(c[i][j]==c[i-1][j])&&(nap!=2))
         {
             ans=1;
             return;
         }
   }
        if (j!=0)
   {
         if ((u[i][j-1]==0)&&(c[i][j]==c[i][j-1])&&(nap!=3))
             dfs(i,j-1,1); else
         if ((u[i][j-1]==1)&&(c[i][j]==c[i][j-1])&&(nap!=3))
         {
             ans=1;
             return;
         }
   }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    {
        cin>>c[i][j];
        u[i][j]=0;
    }



  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    {

        if (u[i][j]==0) dfs(i,j,0);
        if (ans==1)
        {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";
    return 0;
}