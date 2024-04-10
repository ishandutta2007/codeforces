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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,s;
string st;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>st;
    for (int j=0;j<3;j++)
    if (st[j]=='+')++s;
    else if (st[j]=='-')--s;
}
cout<<s/2<<endl;

cin.get();cin.get();
return 0;}