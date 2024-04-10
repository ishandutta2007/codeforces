/*
You are coming for
You're coming to
You're killing for me

Realise
The point is
The pain comes
The body fresh
You're killing for me
Kill for me
Kill for me
Because
Life isn't fair
Because
The chance

With sight
Souls are searching for
Outside
The pain can't be ignored

All around
Lives on the
Fight is yours
Terrorised cities lost
Your world
With the permanent thoughts of hate
With their lies
Die

You are coming for
You're coming to
You're killing for me

Realise
The point is
The pain comes
The body fresh
You're killing for me
Kill for me
Kill for me
Because
Life isn't fair
Because
The chance
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

string st;
long ar[2100][2100],si[2100][2100],sj[2100][2100],mini,maxi,minj,maxj;
long n,m;
long ans,ttl,ai,aj,tcalc;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 {
  cin>>st;
  for (int j=1;j<=m;j++)
  if (st[j-1]=='w')ar[i][j]=1;
  else ar[i][j]=0;
 }

mini=n+1;
maxi=0;
minj=m+1;
maxj=0;

for (long i=1;i<=n;i++)
 for (long j=1;j<=m;j++)
 {
  if (ar[i][j]==0)continue;
  mini=min(mini,i);
  maxi=max(maxi,i);
  minj=min(minj,j);
  maxj=max(maxj,j);
 }

ans=max(maxi-mini,maxj-minj);

for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    {
     si[i][j]=si[i][j-1]+ar[i][j];
     sj[i][j]=sj[i-1][j]+ar[i][j];
     ttl+=ar[i][j];   
    }
}

ai=-1;
aj=-1;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (i+ans>n)continue;
  if (j+ans>m)continue;
  if (ans==0)tcalc=ar[i][j];
  else
  tcalc=(si[i][j+ans]-si[i][j])+(sj[i+ans][j]-sj[i-1][j])+// ang
        (si[i+ans][j+ans]-si[i+ans][j])+(sj[i+ans-1][j+ans]-sj[i][j+ans]);
        if (tcalc==ttl){ai=i;aj=j;}
 }

//cout<<ans<<" "<<ai<<" "<<aj<<endl;

if (ai<0)cout<<-1<<endl;
else
{
    
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
 if (ar[i][j]==1)cout<<"w";
 else if ((i==ai||i==ai+ans)&&j>=aj&&j<=aj+ans)cout<<"+";
 else if ((j==aj||j==aj+ans)&&i>=ai&&i<=ai+ans)cout<<"+";
 else cout<<".";
 cout<<endl;
}
}
cin.get();cin.get();
return 0;}