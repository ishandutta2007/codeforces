/*
Yeah, oh

Waking up with just one thing in mind
Eyes sewn shut so tear them open wide
I'm on the hunt, I'm on the prowl, I can almost taste you now
I'm on your scent, I'll track you down, I'm on you now

Drain your blood, watch it pour
Drain your blood, plead no more

Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy
Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy

Can you feel the pain? The smell of fear's around you
Do you wanna scream? Let it out just know I can hear you
I'm on the hunt, I'm on the prowl. I can almost taste you now
I'm on your scent, I'll track you down, I'm on you now

Drain your blood, watch it pour
Drain your blood, plead no more

Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy
Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy

Drain your blood, watch it pour
Drain your blood, plead no more

Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy
Please forgive me, I don't know what I'm doing
Someone help me, stop begging for your mercy

Oh
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,x0,y0,x[1<<10],y[1<<10],dx,dy,q;
long long gcd(long long a,long long b)
{
 if (a<0)a=-a;
 if (b<0)b=-b;
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

set<pair<long, long> > S;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x0>>y0;
for (int i=0;i<n;i++)
 cin>>x[i]>>y[i];

for (int i=0;i<n;i++)
{
 dx=x[i]-x0;
 dy=y[i]-y0;
 q=gcd(dx,dy);
 dx/=q;
 dy/=q;
 if (dx<0||(dx==0&&dy<0))
  dx*=-1,dy*=-1;
 S.insert(make_pair(dx,dy));
}
cout<<S.size()<<endl;

cin.get();cin.get();
return 0;}