/*
I don't know if we are something between god and demon
Weak mortals, transient beings doing invisible dreams
Eternal I will not lament as I am falling deep to your fears
My angel help me, feel me
As I am falling with tears tor thousand of years
lost into sensations and etherial desires?
I am here like everyone and I will stay forever
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m,c[10000],a,b,t;
double ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>c[i];

for (int i=1;i<=m;i++)
{
 cin>>a>>b>>t;
 ans=max(ans,(c[a]+c[b]+.0)/t);
}
cout.precision(13);

cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}