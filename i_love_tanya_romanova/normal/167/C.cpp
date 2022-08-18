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
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long tests,t,qq,q,i,j,bb[200000],s1,ans[2100][2100];
long long a,b;
long solve(long long a,long long b)
{
     if (a<b)swap(a,b);
     if (a==0||b==0)return 0;
     
     if (solve(a%b,b)==0)return 1;
     t=a/b;
     //cout<<a<<" "<<b<<" "<<t<<endl;
     if (b%2==1)return 1-t%2;
     t%=(b+1);
     if (t%2==1)return 0;
     return 1;
     
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
/*a=b=1000;
ans[0][0]=1;
for (int i=1;i<=1000;i++)ans[i][0]=ans[0][i]=0;
for (int i=0;i<=a;i++)
for (int j=0;j<=b;j++)
{
 if (ans[i][j]==0)
 {
                  if (j<i)for (int q=1;q*i<=1000;q++)ans[j+q*i][i]=ans[i][j+q*i]=1;
                  else for (int q=1;q*j<=1000;q++)ans[i+j*q][j]=ans[j][i+j*q]=1;
                  if (i>0){s1=i;
                  for (;s1<=1000;s1*=i)
                  {if (j+s1>i)ans[j+s1][i]=ans[i][j+s1]=1;if (i==1)break;}
                  }
                  if (j>0){s1=j;
                  for (;s1<=1000;s1*=j){
                  if (i+s1>j)ans[i+s1][j]=ans[j][i+s1]=1;if (j==1)break;}
}}}
*/
//cin>>tests;
//for (;tests;--tests)
//{cin>>a>>b;
//cout<<ans[a][b]<<endl;}
long s=0;
/*for (int i=1;i<=1000;i++){s=0;
for (int j=1;j<=1000;j++)
    if (ans[i][j]==0)s++;
    cout<<i<<" "<<s<<endl;
}
*/

/*
for (int i=1;i<=1000;i++)
{
 a=rand()%1000;
 b=rand()%1000;
 if (ans[a][b]!=solve(a,b))cout<<a<<" "<<b<<endl;
}
*/
/*
bb[0]=1;
cin>>q;
for (int i=0;i<=100;i++)
{if (bb[i]==0)
{bb[i+1]=bb[i+q]=bb[i+q*q]=bb[i+q*q*q]=bb[i+q*q*q]=1;
}
}
for (int i=1;i<=100;i++)
cout<<i<<" "<<bb[i]<<endl;

cin>>tests;
for (;tests;--tests)
{cin>>a>>b;
cout<<solve(a,b)<<endl;
cout<<ans[a][b]<<endl;
}
*/

cin>>tests;
for (;tests;--tests)
{cin>>a>>b;
if (solve(a,b))cout<<"First"<<endl;
else cout<<"Second"<<endl;
}
cin.get();cin.get();
return 0;}