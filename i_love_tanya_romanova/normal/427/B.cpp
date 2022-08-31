/*
Grant amnesty
Fear perception
Spent years of regret

Uneasiness and regretfulness
Burnt out, tapped out, consumed
Debilitated
Weakened not useless
Depreciate, discredit

Spent years of regret
Just waiting for an end
Depleted and winded
Numerous times regretting
Spent years of regret
Spent years of regret

Symptoms surface
Apprehension
Implore for absolution

Spent years of regret
Just waiting for an end
Depleted and winded
Numerous times regretting
Spent years of regret
Spent years of regret

Self accusation into a recognized failure

Uneasiness and regretfulness
Burnt out, tapped out, consumed
Debilitated
Weakened not useless
Depreciate, discredit

Spent years of regret
Just waiting for an end
Depleted and winded
Numerous times regretting
Spent years of regret
Spent years of regret

Regret
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,t,c,l,ans;
long q;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t>>c;
l=0;
for (int i=1;i<=n;i++)
{
 cin>>q;
 if (q>t)l=i;
 if (l<=i-c)ans++;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}