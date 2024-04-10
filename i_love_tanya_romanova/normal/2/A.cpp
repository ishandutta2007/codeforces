#include <iostream>
//#include <fstream>
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
//#define bs 1000000007
#define szz 400
using namespace std;
string nm[20000],nnm[20000];
vector <string> v;
long s[200000],ss[200000],bs,q,n,tq,ansp,anspr;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
{cin>>nm[i]>>s[i];nnm[i]=nm[i];}

sort(nnm,nnm+n);

v.push_back(nnm[0]);
for (int i=1;i<n;i++)if (nnm[i]!=nnm[i-1])v.push_back(nnm[i]);

for (int i=0;i<n;i++)
{for (int j=0;j<v.size();j++)
 if (nm[i]==v[j])ss[j]+=s[i];
}

bs=0;
for (int i=0;i<n;i++)
{if (ss[i]>bs)bs=ss[i];}

ansp=0;
anspr=10000;
for (int i=0;i<v.size();i++)
{
    if (ss[i]==bs)
    {
     q=0;tq=0;
      for (int j=0;j<n;j++)
      {if (nm[j]==v[i])
      q+=s[j];if (q>=bs&&tq==0)tq=j+1;
      }                 
 if (tq<anspr)
 {anspr=tq;ansp=i;}
    }}

cout<<v[ansp]<<endl;

cin.get();cin.get();
return 0;}