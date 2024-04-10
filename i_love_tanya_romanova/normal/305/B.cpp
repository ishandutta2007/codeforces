/*
See the outlaw stands alone beneath the burning sun
The raging badlands now is his home
There's no sign of victory, he lost his liberty
and the only woman that he loved

An outlaw chasing outlaws, a runner in the night
By the radiant moon he will strike
The seeker of all dangers has come to take his toll
From the dead of night he will arise

Renegade, Renegade
Committed the ultimate sin
Renegade, Renegade
This time the prowler will win

He stalks in shadow lands, soundless, with gun in hand
Striking like a reptile, so fierce
No chance to get away, no time for your last prayer
When the prowler sneaks up from behind

An outlaw chasing outlaws, the hunter takes his pray
The law of the jungle he obeys
Craving for the danger to even out the scores
Face to face, once and for all

Renegade, renegade
Committed the ultimate sin
Renegade, renegade
This time the prowler will win

On through the night he rides, on his raging
horse made of steel
Nothing can save you now, before the renegade
you will kneel

Renegade, Renegade
Committed the ultimate sin
Renegade, renegade
This time the prowler will win

Renegade, Renegade
Committed the ultimate sin
Renegade, renegade
This time the prowler will win
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long a,b,p,q;
vector<long long> v,v1;
long long n,t;

long long good()
{if (v.size()!=v1.size())return false;
for (int i=0;i<v.size();i++)
if (v[i]!=v1[i])return false;
return true;}

void solve(long long a,long long b)
{
     if (a==0||b==0)return;
     v1.push_back(a/b);
     a%=b;
     solve(b,a);
} 

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>p>>q;
cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>t;v.push_back(t);
}
if (v.size()>1&&v[n-1]==1)
{
 v.erase(v.end()-1);
 --n;v[n-1]++;
}
solve(p,q);

if (good())cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}