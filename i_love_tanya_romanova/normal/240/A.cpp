//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

string st;

long m,k,gd,ming[1000],bst1,maxg[1000],q,n,good[2000],usd[2000],d[2000],fg,fb,free,bst;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>m>>k;

for (int i=1;i<=k;i++)
{
 cin>>q;good[q]=1;    
}

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>st;
 cin>>d[i];
 gd=0;
 for (int j=1;j<=m;j++)
 usd[j]=0;
 free=0;
 
 for (int j=1;j<=d[i];j++)
 {
     cin>>q;
     usd[q]=1;
     if (q==0)free++;
     else if (good[q])gd++;
 }
 
 fg=fb=0;
 
 for (int j=1;j<=m;j++)
 if (usd[j]==0)
 {if (good[j])fg++; else fb++;}
 
 ming[i]=maxg[i]=gd;
 maxg[i]+=min(fg,free);
 free-=fb;
 if (free>0)ming[i]+=free;
 bst=max(bst,maxg[i]);
 bst1=max(bst1,ming[i]);
}

//for (int i=1;i<=n;i++)
 //{cout<<" "<<maxg[i]<<"  "<<ming[i]<<endl;}
 
for (int i=1;i<=n;i++)
{
    long fl;
    
    fl=0;
    for (int j=1;j<=n;j++)
    if (maxg[j]>ming[i]&&i!=j)
    fl=1;
    
    if (fl==0)cout<<0<<endl;
    else if (maxg[i]<bst1)cout<<1<<endl;
    else cout<<2<<endl;
}

cin.get();cin.get();
return 0;}