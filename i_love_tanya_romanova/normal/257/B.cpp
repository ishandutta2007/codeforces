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

vector<long> v;
long ans[100],tans[100];
long ar[200000];
long n,m;
void mod (long a,long b)
{
     if (ar[a]==0&&ar[1-a]==0)return;
     if (ar[a]==0)
     {mod(1-a,b);}
     else
     {
         ar[a]--;
         v.push_back(a);
         if (b==0)mod(1-a,1-b);
         else mod(a,1-b);
         return;
     }
}

void calc()
{
 for (int i=1;i<v.size();i++)
 {
     if (v[i]==v[i-1])ans[0]++; else ans[1]++;
 }    
}

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
ans[0]=ans[1]=0;
tans[0]=tans[1]=0;
ar[0]=n;ar[1]=m;

v.clear();
mod(0,0);
calc();
v.clear();
tans[0]=ans[0];
tans[1]=ans[1];
ans[0]=ans[1]=0;

ar[0]=n;ar[1]=m;

mod(1,0);
calc();
if (tans[0]>ans[0])
{
                   cout<<tans[0]<<" "<<tans[1]<<endl;
}
else
if (tans[0]<ans[0])
cout<<ans[0]<<" "<<ans[1]<<endl;

else
{
 cout<<ans[0]<<" ";
 cout<<min(ans[1],tans[1])<<endl;
}


cin.get();cin.get();
return 0;}