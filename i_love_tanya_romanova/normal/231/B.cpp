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

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long long n,r,l,q,qq,ar[100000];
int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>r>>l;
qq=r;

for (int i=1;i<=n;i++)
{ar[i]=1;if (i%2)--qq;else ++qq;}

for (int i=1;i<=n;i+=2)
{
    q=min(qq,l-1);
    if (q<0)q=0;
    ar[i]+=q;
    qq-=q;
   // cout<<qq<<" "<<q<<" "<<i<<endl;
}

//for (int i=1;i<=n;i++)
//cout<<ar[i]<<" ";
//cout<<endl;
//cout<<qq<<endl;
qq=-qq;

for (int i=2;i<=n;i+=2)
{
    q=min(qq,l-1);
    if (q<0)q=0;
    ar[i]+=q;
    qq-=q;
}

if (qq==0)

{
          for (int i=0;i<n;i++)
          {if (i)cout<<" ";
          cout<<ar[i+1];
          }
          cout<<endl;
          }
else cout<<-1<<endl;
cin.get();cin.get();
return 0;}