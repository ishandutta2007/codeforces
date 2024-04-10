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
#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,k,ar[20000],p;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
scanf("%d%d",&n,&k);
for (int i=1;i<=n;i++)scanf("%d",&ar[i]);
ar[n+1]=1;

while (ar[k]==0){++k;if(k>n)k=1;}

cout<<k<<endl;
cin.get();cin.get();
return 0;
}