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
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,ar[10000],bst[10000];
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];

bst[0]=ar[0];
bst[1]=min(bst[0],ar[1]);

for (int i=2;i<n;i++)
{bst[i]=max(bst[i-1],bst[i-2]);
bst[i]=min(bst[i],ar[i]);}

cout<<bst[n-1]<<endl;

cin.get();cin.get();
return 0;}