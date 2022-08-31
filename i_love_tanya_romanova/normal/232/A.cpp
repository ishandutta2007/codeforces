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
#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
#define j1 assdgsdgasghsf
#define MAXN 100000
#define tm sdfjahlfasfh
using namespace std;

long ar[200][200],e,q,sz,fr,n,tt;
void dofull(long q)
{
     for (int i=1;i<=q;i++)
     for (int j=1;j<=q;j++)
     if (i!=j)ar[i][j]=1;
}

void conn(long a,long b)
{
     for (int i=1;i<=a;i++)
     ar[i][b]=ar[b][i]=1;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

tt=100;

cin>>sz;
//n=100;
n=tt;

q=1;
while (q*(q-1)*(q-2)/6<=sz)++q;

--q;

//cout<<q<<"   "<<sz<<endl;

dofull(q);
sz-=q*(q-1)*(q-2)/6;

fr=tt-q;

for (int i=1;i<=fr;i++)
{
 e=0;
 while(e*(e+1)/2<=sz&&e<q)++e;
 conn(e,q+i);sz-=e*(e-1)/2;   
}

cout<<tt<<endl;
for (int i=1;i<=tt;i++)
{
    for (int j=1;j<=tt;j++)
    cout<<ar[i][j];
    cout<<endl;
}

cin.get();cin.get();
return 0;}