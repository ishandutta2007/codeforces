#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long n,ansp,ansl,q,w;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
ansl=10000000;
for (int p=0;p<=n;p++)
{q=p*7;if (q>n)continue;
 w=n-q;
 if (w%4!=0)continue;
 if (p+w/4<ansl){ansl=p+w/4; ansp=p;};}
if (ansl>1000000)cout<<-1<<endl;
else 
{for (int i=n-7*ansp;i;i-=4)printf("%d",4);
 for (int i=1;i<=ansp;i++)printf("%d",7);
     
 cout<<endl;}
cin.get();cin.get();
return 0;
}