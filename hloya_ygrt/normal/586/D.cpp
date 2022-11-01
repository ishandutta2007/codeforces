#include <stdio.h>
#include <string>
using namespace std;

int o[100000][2];
int main()
{
   int t;
   scanf("%d",&t);

   for (int k=0;k<t;k++)
   {
       int n,l;
        int were[105][3];
       char p[103][3],p1[103],p2[103],p0[103];
       scanf("%d %d",&n,&l);
       int s;

           scanf("%s",p0);
           for (int i=0;i<n;i++)
           {
               p[i][0]=p0[i];
           }
           if (p[0][0]=='s') s=0;

            scanf("%s",p1);
           for (int i=0;i<n;i++)
           {
               p[i][1]=p1[i];
           }
           if (p[0][1]=='s') s=1;

            scanf("%s",p2);
           for (int i=0;i<n;i++)
           {
               p[i][2]=p2[i];
           }
           if (p[0][2]=='s') s=2;






        for (int i=0;i<3;i++)
        for (int j=0;j<n;j++)
        were[j][i]=0;

       int ans=0;
       int ti=0,tj=s;
       int lo=0,ro=0;

       o[ro][0]=ti;
       o[ro][1]=tj;
       ro++;

        while ((n-1)%3!=0)
        {
            were[n][0]=were[n][1]=were[n][2]=0;
            p[n][0]=p[n][1]=p[n][2]='.';
            n++;

        }

       while (lo<ro)
       {

           ti=o[lo][0];
           tj=o[lo][1];
           were[ti][tj]=1;
           if (p[ti+3][tj]=='.'&&!were[ti+3][tj])
           {
              if (p[ti+1][tj]==p[ti+2][tj]&&p[ti+2][tj]=='.')
              {
                  o[ro][0]=ti+3;
                  o[ro][1]=tj;
                  ro++;
                  were[ti+3][tj]=1;
                   if (ti+3==n-1)
              {
                  ans=1;
                  break;
              }
              }
             
           }
           if (tj!=2)
           {
                 if (p[ti+3][tj+1]=='.'&&!were[ti+3][tj+1])
           {
              if (p[ti+1][tj+1]==p[ti+2][tj+1]&&p[ti+2][tj+1]=='.'&&p[ti+1][tj]=='.')
              {
                  o[ro][0]=ti+3;
                  o[ro][1]=tj+1;
                  ro++;
                    were[ti+3][tj+1]=1;
                    if (ti+3==n-1)
              {
                  ans=1;
                  break;
              }
              }
              
           }

           }
           if (tj!=0)
           {
                     if (p[ti+3][tj-1]=='.'&&!were[ti+3][tj-1])
           {
              if (p[ti+1][tj-1]==p[ti+2][tj-1]&&p[ti+2][tj-1]=='.'&&p[ti+1][tj]=='.')
              {
                  o[ro][0]=ti+3;
                  o[ro][1]=tj-1;
                  ro++;
                    were[ti+3][tj-1]=1;
                     if (ti+3==n-1)
              {
                  ans=1;
                  break;
              }
              }
             
           }
           }


           lo++;

       }
        if (ans==0) printf("NO\n"); else printf("YES\n");
   }

    return 0;
}