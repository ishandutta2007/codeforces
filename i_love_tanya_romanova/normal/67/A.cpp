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
//#define bs 1000000007
//#define szz 400
using namespace std;
char t[20000];
long ar[2000],n;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<n;i++)cin>>t[i];

for (int i=1;i<=n;i++)ar[i]=1;

for (int mvs=1;mvs<=1000;mvs++)
for (int i=1;i<n;i++)
{if (t[i]=='L'&&ar[i]<=ar[i+1])ar[i]=ar[i+1]+1;
 if (t[i]=='='&&ar[i]<ar[i+1])ar[i]=ar[i+1];
 if (t[i]=='='&&ar[i]>ar[i+1])ar[i+1]=ar[i];
 if (t[i]=='R'&&ar[i]>=ar[i+1])ar[i+1]=ar[i]+1;}

for (int i=1;i<=n;i++)cout<<ar[i]<<" ";
cout<<endl;

cin.get();cin.get();
return 0;}