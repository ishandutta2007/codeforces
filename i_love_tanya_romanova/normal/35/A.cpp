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
#define bs 1000000007
using namespace std;
long a,q,w,ar[200];
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin>>a;
ar[a]=1;
for (int i=1;i<=3;i++)
{cin>>q>>w;
 swap(ar[q],ar[w]);
}
q=1;
while (ar[q]==0)++q;
cout<<q<<endl;

cin.get();cin.get();
return 0;}