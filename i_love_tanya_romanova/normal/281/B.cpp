/*
Make his fight on the hill in the early day
Constant chill deep inside
Shouting gun, on they run through the endless grey
On they fight, for the right, yes but who's to say?
For a hill men would kill why? They do not know
Stiffened wounds test their pride
Men of five, still alive through the raging glow
Gone insane from this pain that they surely know

For whom the bell tolls
Time marches on
For whom the bell tolls

Take a look to the sky just before you die
It is the last time you will
Blackened roar massive roar fills the crumbling sky
Shattered goal fills his soul with a ruthless cry
Stranger now, are his eyes, to this mystery
He hears the silence so loud
Crack of dawn, all is gone except the will to be
Now they will see what will be, blinded eyes to see

For whom the bell tolls
Time marches on
For whom the bell tolls
*/

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
#define bs 1000000009
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long aa,bb,x,y,n,v1,v2;
double bdif;

void check(long a,long b)
{
 if (fabs(a*1.0/b-x*1.0/y)<bdif-1e-16)
 {
  bdif=fabs(a*1.0/b-x*1.0/y);
  aa=a;bb=b;
 }
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>y>>n;
bdif=1000000;

for(int i=1;i<=n;i++)
{
        v1=x*1.0/y*i-1e-6;
        v2=v1+1;
 
      //  if (i>n-5)cout<<v1<<" "<<v2<<endl;
               
        check(v1,i);
        check(v2,i);
}

cout<<aa<<"/"<<bb<<endl;
 
cin.get();cin.get();
return 0;}