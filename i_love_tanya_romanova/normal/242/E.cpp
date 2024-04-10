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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long q,n,m,ar[101000];
long s[101000];
long par[101000];
long clc,ps,a,b,tp,c;
long long r;
long temp,calc;

long long gs(long long a,long long b)
{
 r=temp=calc=0;
 
 for (int i=a;i<=b;i++)
 {
     temp+=ar[i];
     ++calc;
     if (calc>2042)
     {
           calc=0;r+=temp;temp=0;        
     }
 }
 r+=temp;
 return r;    
}

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];}

cin>>m;
for (int i=1;i<=m;i++)
{
    cin>>tp;
    if (tp==1)
    {
              cin>>a>>b;
             
 r=temp=calc=0;
 
 for (int i=a;i<=b;i++)
 {
     temp+=ar[i];
    // ++calc;
     if (temp>2100000000)
     {
           r+=temp;temp=0;        
     }
 }
 r+=temp;
 cout<<r<<endl;
    }
    else
    {
       cin>>a>>b>>c;
       for (int j=a;j<=b;j++)
       {
           ar[j]^=c;
       } 
    }
}

cin.get();cin.get();
return 0;}