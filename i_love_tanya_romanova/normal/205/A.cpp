//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
#define MAXN 1000000

long n,bp,ar[200000],s;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
bp=1;
for (int i=1;i<=n;i++)
if(ar[i]<ar[bp])bp=i;
s=0;
for (int i=1;i<=n;i++)
if (ar[i]==ar[bp])++s;
if (s==1)cout<<bp<<endl; else cout<<"Still Rozdil"<<endl;
cin.get();cin.get();
return 0;}