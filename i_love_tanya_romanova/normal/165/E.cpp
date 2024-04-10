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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long ar[2000000],t,r,n,ms[5000000];
long inv(long a)
{
     r=0;
     for (int i=0;i<22;i++)
     if ((a&(1<<i))==0)r|=(1<<i);
     return r;
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
scanf("%d",&n);
for (int i=0;i<n;i++)
{
   // cin>>ar[i];
   scanf("%d",&ar[i]);
    ms[ar[i]]=ar[i];

}
    for (int j=0;j<(1<<22);j++)
    {
        if (ms[j]>0)
        {
                    for (int q=0;q<22;q++)
                        {
                         if ((ms[j]&(1<<q))==0)ms[j|(1<<q)]=ms[j];
                        }
                    }
    }
    
for (int i=0;i<n;i++){
if (i)printf(" ");
t=~ar[i];
t&=((1<<22)-1);//inv(ar[i]);
if (ms[t]==0)printf("%d",-1);
else printf("%d",ms[t]);
}
printf("\n");

cin.get();cin.get();
return 0;}