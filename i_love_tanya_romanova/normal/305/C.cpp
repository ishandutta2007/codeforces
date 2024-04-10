/*
Truth in redemption's pyre
Scorched out, no longer in life
Awaiting these souls on fire
In life, there's no brighter side

Once hateful as all its slaves
More fertile than its enemies
Impossible to control
But still a reason for us to live on

Keep away from scarecrows dreams
Dismay feeds all these marionettes
See the truth and manipulation
With lies they breed all these marionettes

Truth over denial inside a thought bleaker than life
Lustre of all that remains is the day
when we all are the same
Adapted to black, still on way down
Beyond redemption in a state stronger than hate

Truth over all dreams
Deceit to feed the desolated breed
The point of all that's been done
Is the moment we all are gathered as one
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

long n,q;
multiset<long> v;
multiset<long>::iterator it;
long q1,q2;

vector<long> v1;
long t;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 v.insert(q);
}


while (v.size())
{
 it=v.begin();
 q1=(*it);
 it++;
 q2=(*it);
 if (v.size()>1&&q1==q2)
 {
  v.erase(v.begin());v.erase(v.begin());
  v.insert(q1+1);
 }
 else 
 {
  v1.push_back(q1);
  v.erase(v.begin());
 }
}
sort(v1.begin(),v1.end());
long t=v1.back();
cout<<t-v1.size()+1<<endl;

cin.get();cin.get();
return 0;}