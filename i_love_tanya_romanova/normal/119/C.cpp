#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
 pair <long long, long long> p;
 vector <pair <long long ,long long> > v1;
 long long r;
long long n,m,k,nmb[200000],a[200000],b[200000],pp,v,t1,t2,
c[200000],ans[105][105][105],prev1[105][105][105],ans1[105][105][105],prev2[105][105][105];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>m>>k;

for (long long i=1;i<=m;i++)
{cin>>a[i]>>b[i]>>c[i];}

for (long long i=1;i<=m;i++)
{nmb[i]=i;
}

for (long long i=1;i<=m;i++)
for (long long j=1;j<=m;j++)
{if (c[nmb[i]]<c[nmb[j]])swap(nmb[i],nmb[j]);
}

/*
for (int i=1;i<=m;i++)
{cout<<nmb[i]<<endl;
}*/

ans[0][0][0]=1;


for (long long i=1;i<=n;i++)
{for (long long j=1;j<=m;j++)
  for (long long q=0;q<=b[nmb[j]]-a[nmb[j]];q++)
  {//cout<<i<<" "<<j<<" "<<q<<" "<<b[nmb[j]]<<" "<<a[nmb[j]]<<endl;
     pp=nmb[j];
     for (long long w=0;w<j;w++)if (c[nmb[w]]<c[pp])
     {
      
      t1=a[pp]+q-k-a[nmb[w]];   
      if((a[pp]+q)%k==0)t2=(a[pp]+q)/k-a[nmb[w]];
      else t2=-1;
      
      if (w==0)t1=t2=0;
      
      if (t1>=0&&t1<=b[nmb[w]]-a[nmb[w]]&&ans[i-1][w][t1]==1&&ans1[i-1][w][t1]+q+a[nmb[j]]>ans1[i][j][q]
      )
      {ans[i][j][q]=1;
       prev1[i][j][q]=w;
       prev2[i][j][q]=1;
       ans1[i][j][q]=ans1[i-1][w][t1]+q+a[nmb[j]];
       //nextt1[i-1][w][t1-a[nmb[w]]]=q;
       //nextt2[i-1][w][t1-a[nmb[w]]]=1;
                                         }
       if (t2>=0&&t2<=b[nmb[w]]-a[nmb[w]]&&ans[i-1][w][t2]==1&&ans1[i-1][w][t2]+q+a[nmb[j]]>ans1[i][j][q]
       )
       {
       ans[i][j][q]=1;
       prev1[i][j][q]=w;
       prev2[i][j][q]=2;
       ans1[i][j][q]=ans1[i-1][w][t2]+q+a[nmb[j]];
       //nextt1[i-1][w][t1-a[nmb[w]]]=q;
       //nextt2[i-1][w][t1-a[nmb[w]]]=2;
                                          }
                                          
          //  if (i==6&&j==8&&q==10)cout<<a[pp]+q<<" "<<w<<" "<<t1<<" "<<ans1[i-1][w][t1]<<" "<<b[nmb[w]]-a[nmb[w]]<<" "<<ans1[i][j][q]<<endl;
     }
      
 }
 // cout<<ans1[6][8][10]<<endl;
}

long long answ=0;

 // cout<<ans1[6][8][10]<<endl;
for (long long i=1;i<=m;i++)
for (long long j=0;j<=b[nmb[i]]-a[nmb[i]];j++)
if (ans[n][i][j]){answ++;
}

  //cout<<ans1[6][8][10]<<endl;
if (answ==0)cout<<"NO"<<endl;
else 
{
//  cout<<ans1[6][8][10]<<" "<<ans[6][8][10]<<endl;
     long long ap1,ap2;
     cout<<"YES"<<endl;
     ap1=ap2=0;long long ansss=0;
     for (long long i=1;i<=m;i++)
      for (long long j=0;j<=b[nmb[i]]-a[nmb[i]];j++)
       if ((ans[n][i][j])&&(ans1[n][i][j]>ansss))
          {//cout<<i<<" "<<j<<endl;//cout<<ans1[n][i][j]<<endl//>ansss
         // ;
          ap1=i;ap2=j;ansss=ans1[n][i][j];}
//cout<<ansss<<endl;

     for (int i=1;i<=n;i++)
     {p=make_pair(nmb[ap1],ap2+a[nmb[ap1]]);
      v1.push_back(p);
      r=ap2+a[nmb[ap1]];
      if (prev2[n-i+1][ap1][ap2]==1)r-=k;
      else r/=k;
      ap1=prev1[n-i+1][ap1][ap2];
      ap2=r-a[nmb[ap1]];
     }     
     
 for (long long i=n-1;i+1;--i)
 cout<<v1[i].first<<" "<<v1[i].second<<endl;
 
}

cin.get();cin.get();
return 0;
}