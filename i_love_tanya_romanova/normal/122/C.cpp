/*
Blank face in the windowpane
Made clear in seconds of light
Disappears and returns again
Counting hours, searching the night

Might be waiting for someone
Might be there for us to see
Might be in need of talking
Might be staring directly at me

Inside plays a lullaby
Slurred voice over children cries
On the inside

Haunting loneliness in the eye
Skin covering secret scars
His hand is waving a goodbye
There's no response or action returned

There is deep prejudice in me
Outshines all reasons inside
Given dreams all ridden with pain
And projected unto the last
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;
long long i,qw,ans,q,l,r;
vector <long long> luck;
long long solve(long long a)
{
     long long ans=0;
 for (int i=1;i<luck.size();i++)
 {if (a>luck[i-1]){qw=min(a,luck[i])-luck[i-1];
  ans+=luck[i]*qw;}}
 return ans;
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
luck.push_back(4);
luck.push_back(7);

i=0;

while (true)
{if (i>=luck.size())break;
 q=luck[i];
 if (q>1000000000)break;
 luck.push_back(q*10+4);
 luck.push_back(q*10+7);
 ++i;
}
luck.push_back(0);
sort(luck.begin(),luck.end());
cin>>l>>r;
cout<<solve(r)-solve(l-1)<<endl;

 cin.get();cin.get();
return 0;
 }