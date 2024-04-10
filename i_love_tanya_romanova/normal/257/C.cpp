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

long n;
double x[1000000],y[1000000],ang,d;
double mx;
double ar[200000];
int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>x[i]>>y[i];

for (int i=0;i<n;i++)
{
 d=(x[i]*x[i]+y[i]*y[i]);
 d=sqrt(d);
 ang=acos(x[i]/d);
 if(y[i]<0)ang=2*M_PI-ang;
 //cout<<ang<<" "<<x[i]<<" "<<y[i]<<endl;
 ar[i]=ang;
}
sort(ar,ar+n);
mx=0;
for (int i=1;i<n;i++)
mx=max(mx,ar[i]-ar[i-1]);

mx=max(mx,2*M_PI-ar[n-1]+ar[0]);
cout.precision(8);
if (mx<eps)cout<<fixed<<0<<endl; else cout<<fixed<<(2*M_PI-mx)*360/2/M_PI<<endl;

cin.get();cin.get();
return 0;}