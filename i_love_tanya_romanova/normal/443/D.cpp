/*
Looking at myself in the mirror, is it me?
Anybody there? I ask myself and look away
Feeling weird things in my head, controlling me?
Hearing strange voices everywhere, calling me?
All illusion?

What is happening to me, my hands are working
Without my own will
Is there someone else inside of me, who are you?
I know i'm not dreaming
Somebody tortures me all the time
Got my own soul escape my body, filled with
Torture and pain

No commands, no more
Take no orders from you no more
No commands, no more
I'm on my own, don't own me anymore

Evil powers try to take me, can I bet the same
Anymore
But I'll whip you out myself, out of my mind
Evil torture and hell's fire
Gonna rule me no more
Still I'm scared 'cos I can't know
Will my sould come back
Come back!

No commands, no more
Take no orders from you no more
No commands, no more
I'm on my own, don't own me anymore
*/

#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n;
double bst,temp,ar[200];
long bmask;

double solve(vector<double> v)
{
 double r=0;
 for (int i=0;i<v.size();i++)
 {
  double t=1;
  for (int j=0;j<v.size();j++)
  if (i==j)t*=v[j];else t*=(1.0-v[j]);
   r+=t;
 }
 return r;
}

double cur;
vector<double> ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
/*for (int i=0;i<n;i++)
ar[i]=rand()%100*.01;
*/
for (int i=0;i<n;i++)
cin>>ar[i];

sort(ar,ar+n);
reverse(ar,ar+n);
ans.push_back(ar[0]);
cur=solve(ans);

for (int i=1;i<n;i++)
{
 ans.push_back(ar[i]);
 if (solve(ans)>cur){cur=solve(ans);continue;}
 ans.pop_back();
}
cout.precision(12);

cout<<fixed<<cur<<endl;

cin.get();cin.get();
return 0;}