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
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
//#define SIZE 60
using namespace std;

long long n,ar[200000],bx,tt,mxo,cvrd,ch;

int main(){
//freopen("elevator.in","r",stdin);
//freopen("elevator.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
 
 
 cin>>n;
 for (int i=1;i<=n;i++)
 cin>>ar[i];
 cin>>bx;
 
 
 cvrd=0;
 ch=0;
 
 for (;bx;--bx)
 {
     cin>>tt;
     mxo=0;
     
     for (int j=cvrd+1;j<=tt;j++)
     mxo=max(mxo,ar[j]);
     
     cvrd=max(cvrd,tt);
     
     mxo=max(mxo,ch);
     cout<<mxo<<endl;
     ch=mxo;
     cin>>tt;
     ch+=tt;
 }
 
cin.get();cin.get();
return 0;}