/*
Can I spread frustration
Without speaking
Without parting my lips
Except to breath?

I let my actions speak for me
Because my words collided with yours
It created tension and frustration
So I left

I didn't turn around to see
How troubled you were that night
I promise that it paled in comparison
To the anguish each step brought me

As I walked away
My heart pumps your rhapsody
I still lick my lips
To the thought of you

So now I'm stuck here
In the purgatory of longing
For that one kiss goodbye
I try to empty myself
Of all desire that I crave for you

But the attempt only brings me to my knees
I succumb to you idol
This subconscious social vampire
Who haunts every thought
I chock on the will to demand patience
Only to find myself swallowing blood
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,r,avg,need,a,b;
vector<pair<long long, long long> > v;
long long ca;
long long ans;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>r>>avg;
need=avg*n;
for (int i=0;i<n;i++)
 {
  cin>>a>>b;
  v.push_back(make_pair(b,a));       
  need-=a;
 }

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    ca=r-v[i].second;
    ca=min(ca,need);
    if (ca<0)ca=0;
    ans+=ca*v[i].first;
    need-=ca;
}
cout<<ans<<endl;


cin.get();cin.get();
return 0;}