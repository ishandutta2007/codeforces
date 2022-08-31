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

long long n,ar[200000],cl[200000];
long long s1,s2;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<n;i++)
{
    cin>>ar[i];
}

s1=s2=0;
for (int i=n-1;i+1;--i)
{
 if (s1<s2)
 {
 // v1.push_back(i);
 cl[i]=1; s1+=ar[i];         
 }   
 else
 {
//  v2.push_back(i);
 cl[i]=2;
  s2+=ar[i];
 }
}

if (s1<s2)
for (int i=0;i<n;i++)
cl[i]=3-cl[i];

for (int i=0;i<n;i++)
if (cl[i]==1)cout<<"+"; else cout<<"-";
cout<<endl;

cin.get();cin.get();
return 0;}