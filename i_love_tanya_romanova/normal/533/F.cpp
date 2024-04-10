/*
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
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define move adsfasdfasd

#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long pw1[1<<20],pw2[1<<20];
long n,m;
string st;
long A[1<<20],B[1<<20];
long val[1<<18][27],val1[1<<18][27];
long H11[1<<18][27],H12[1<<18][27],H21[1<<18][27],H22[1<<18][27];
long match[100];
vector<long> ans;

pair<long long, long long> g1(long l,long r,long p)
{
 pair<long long, long long> res;
 res.first=H11[r][p]-H11[l][p];
 if (res.first<0)res.first+=bs;
 res.second=H12[r][p]-H12[l][p];
 if (res.second<0)res.second+=bs;
 return res;
}

pair<long long, long long> g2(long l,long r,long p)
{
 pair<long long, long long> res;
 res.first=H21[r][p]-H21[l][p];
 if (res.first<0)res.first+=bs;
 res.second=H22[r][p]-H22[l][p];
 if (res.second<0)res.second+=bs;
 return res;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw1[0]=pw2[0]=1;

for (int i=1;i<=1000000;i++)
{ pw1[i]=pw1[i-1]*173,
  pw2[i]=pw2[i-1]*137;
  pw1[i]%=bs;
  pw2[i]%=bs;
}

cin>>n>>m;
cin>>st;
for (int i=0;i<n;i++)
 A[i]=st[i]-'a';
 
for (int i=0;i<26;i++)
{
 val[n][i]=i;   
} 

for (int i=n-1;i+1;--i)
{
 for (int j=25;j+1;--j)
 {
  val[i][j]=val[i+1][j];
 }
 for (int j=25;j+1;--j)
  if (A[i]==val[i][j]&&j>0)
   swap(val[i][j],val[i][j-1]);
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<26;j++)
 {
  H11[i][j]=H11[i-1][j],
  H12[i][j]=H12[i-1][j];
  if (j!=A[i-1])continue;
  H11[i][j]+=pw1[i-1];//*st[i-1];
  H12[i][j]+=pw2[i-1];//*st[i-1];
  H11[i][j]%=bs;
  H12[i][j]%=bs;
 }
}

cin>>st;
for (int i=0;i<m;i++)
 B[i]=st[i]-'a';

for (int i=0;i<26;i++)
 val1[m][i]=i;
for (int i=m-1;i+1;--i)
{
 for (int j=25;j+1;--j)
 {
  val1[i][j]=val1[i+1][j];
 }
 for (int j=25;j+1;--j)
  if (B[i]==val1[i][j]&&j>0)
   swap(val1[i][j],val1[i][j-1]);
}

for (int i=1;i<=m;i++)
{
 for (int j=0;j<26;j++)
 {
  H21[i][j]=H21[i-1][j],
  H22[i][j]=H22[i-1][j];
  if (j!=B[i-1])continue;
  H21[i][j]+=pw1[i-1];//*st[i-1];
  H22[i][j]+=pw2[i-1];//*st[i-1];
  H21[i][j]%=bs;
  H22[i][j]%=bs;
 }
}

for (int i=0;i<=(n-m);i++)
{
    for (int j=0;j<26;j++)
     match[j]=-1;
    int er=0;
    for (int j=0;j<26;j++)
    {
     int id1=val[i][j];
     int id2=val1[0][j];
//     cout<<i<<"^"<<j<<" "<<id1<<" "<<id2<<" "<<" "<<H11[i+m][id1]<<" "<<H11[i][id1]<<endl;
     if (H11[i+m][id1]==H11[i][id1])break;
     if (match[id1]!=-1&&match[id1]!=id2){er=1;break;}
     if (match[id2]!=-1&&match[id2]!=id1){er=1;break;}
     match[id1]=id2;
     match[id2]=id1;
     pair<long long, long long> tp1=g1(i,i+m,id1);
     pair<long long, long long> tp2=g2(0,m,id2);
     tp2.first*=pw1[i];
     tp2.second*=pw2[i];
     tp2.first%=bs;
     tp2.second%=bs;
//     cout<<tp1.first<<"&"<<tp1.second<<" "<<tp2.first<<" "<<tp2.second<<endl;
     if (tp1.first!=tp2.first||tp1.second!=tp2.second)
      {er=1;break;}
    }/*
    for (int j=0;j<26;j++)
     cout<<j<<"  ^ "<<match[j]<<endl;
     cout<<endl;
     */
     if (er==0)
      ans.push_back(i+1);
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}