#include<bits/stdc++.h>
using namespace std;
int ans4,ans3;
int p3[20000],p4[20000],q3[20000],q4[20000],cnt,n,m,x,y,i,j,ans,ans1,ans2,a[20000],b[20000],d[20000],f[3030][3030],e[3030][3030],q1[20000],q2[20000],p1[20000],p2[20000];
priority_queue< pair < int ,int >, vector < pair < int ,int > > ,greater< pair < int ,int > > > q;
bool u[3030][3030];
void add(int x,int y)
{
    cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++)
         {
             cin>>x>>y;
             add(x,y);
         }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
           f[i][j]=100000000;
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
          f[i][i]=0;
    for (j=1;j<=n;j++)
         {
             while (!(q.empty())) q.pop();
             q.push(make_pair(0,j));
             f[j][j]=0;
             while (!(q.empty()))
                  {
                  x=q.top().second;q.pop();
                  if (u[j][x]) continue;u[j][x]=true;
                  for (i=d[x];i;i=b[i])
                       if (f[j][x]+1<f[j][a[i]])
                           {
                               f[j][a[i]]=f[j][x]+1;
                               q.push(make_pair(f[j][a[i]],a[i]));
                           }
                  }
         }
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
            e[i][j]=f[j][i];
    for (i=1;i<=n;i++)
         {
             ans=0;ans1=0;ans2=0;ans3=0;
             for (j=1;j<=n;j++)
              if (i!=j)
                if (e[i][j]!=100000000)
                if (e[i][j]>ans) 
                    {
                        ans2=ans;ans3=ans1;
                        ans=e[i][j];ans1=j;
                    }
            else if (e[i][j]>ans2)
                    {
                        ans2=e[i][j];ans3=j;
                    }
            p1[i]=ans;p2[i]=ans1;
            p3[i]=ans2;p4[i]=ans3;
         }
    for (i=1;i<=n;i++)
         {
             ans=0;ans1=0;ans2=0;ans3=0;
             for (j=1;j<=n;j++)
               if (i!=j)
                if (f[i][j]!=100000000)
                   {
                if (f[i][j]>ans) 
                    {
                        ans2=ans;ans3=ans1;
                        ans=f[i][j];ans1=j;
                    }
            else if (f[i][j]>ans2)
                   {
                   ans2=f[i][j];ans3=j;
                   }
                   }
            q1[i]=ans;q2[i]=ans1;
            q3[i]=ans2;q4[i]=ans3;
         }
    ans=0;
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
         if ((p2[i]>0)&(q2[j]>0))
         if (i!=j)
           if (f[i][j]!=100000000)
               {
                   if ((p2[i]!=j)&(q2[j]!=i))
                     {
           if ((f[i][j]+p1[i]+q1[j]>ans)&(p2[i]!=q2[j]))
               {
                   ans=f[i][j]+p1[i]+q1[j];
                   ans1=i;ans2=j;ans3=p2[i];ans4=q2[j];
               }
            else if ((p2[i]==q2[j]))
                {
                   if ((f[i][j]+p3[i]+q1[j]>ans)&(p4[i]!=j)&(p4[i]!=q2[j]))
                          {
                   ans=f[i][j]+p3[i]+q1[j];
                   ans1=i;ans2=j;ans3=p4[i];ans4=q2[j];
               }
               if ((f[i][j]+p1[i]+q3[j]>ans)&(q4[j]!=i)&(q4[j]!=p2[i]))
                     {
                     ans=f[i][j]+p1[i]+q3[j];
                   ans1=i;ans2=j;ans3=p2[i];ans4=q4[j];
                     }
                }
                     }
        else if ((p2[i]==j)&(q2[j]!=i))
               {
if ((f[i][j]+p3[i]+q1[j]>ans)&(p4[i]>0)&(q2[j]!=p4[i])&(p4[i]!=j))
               {
                   ans=f[i][j]+p3[i]+q1[j];
                   ans1=i;ans2=j;ans3=p4[i];ans4=q2[j];
               }
               }
        else if (((p2[i]!=j)&(q2[j]==i)))
              {
              if ((f[i][j]+p1[i]+q3[j]>ans)&(q4[j]>0)&(q4[j]!=p2[i])&(q4[j]!=i))
               {
                   ans=f[i][j]+p1[i]+q3[j];
                   ans1=i;ans2=j;ans3=p2[i];ans4=q4[j];
               }
              }
        else  if ((f[i][j]+p3[i]+q3[j]>ans)&(p4[i]>0)&(q4[j]>0)&(q4[j]!=p4[i])&(q4[j]!=i)&(p4[i]!=j))
               {
                   ans=f[i][j]+p3[i]+q3[j];ans1=i;ans2=j;ans3=p4[i];ans4=q4[j];
               }
               }
    cout<<ans3<<" "<<ans1<<" "<<ans2<<" "<<ans4<<endl;
    return 0;
}