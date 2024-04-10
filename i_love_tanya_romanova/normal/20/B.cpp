/*
No sun for the grey children
Waiting to catch the strange
Airy notions of that place
Now they evolutions
Means their brain mutations
The wider is the comprehension
The deeper and stronger is the illusion
They're no more material
Since they're invisible
High pressure inside me
Erasure, I'm empty
With their talk, they fill me
Now I walk, so brainy
Who's in my head, hiding themselves
It hurts me so, it's a brainscan
Who's it instead, instead myself
I hate it so, it's a brain scan
Creeping in your double mind
There's nothing they can't find
You've lost all your energy
Not able to set you free
They will own you just like me
Just like me, just like me...
High pressure inside me
Erasure, I'm empty
With their talk, they fill me
Now I walk, so brainy
Some times I feel
Their cold presence
Checking my mind, it's a brain scan
Sometimes my soul
Can't reach a sense
This head is mine, it's a brain scan
Don't ask'em to give a break
You can't even close the gate
Passing through both hemispheres
Searching in all memories
Knowing what's inside of me
Side of me, side of me....
Perceptive entity
Emotive synergy
Hyper-detection
Suck out the reason
Is there something I could feel
Translucid language
Reflect the new age
Words are a limitation
Locking me out of my skull
Something without physical
Disturbing my frequency
Terminate identity
Out of me, out of me...
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

double a,b,c,det;
vector<double> res;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>c;
if (a==0&&b==0&&c==0)
{
 cout<<-1<<endl;
 return 0;
}
if (a==0)
{
 if (b)res.push_back(-c/b);
}
else
{
 det=b*b-4*a*c;
 if (det>=-eps)res.push_back((-b+sqrt(det))/2.0/a);
 if (det>0)res.push_back((-b-sqrt(det))/2.0/a);
}
sort(res.begin(),res.end());
cout.precision(15);
cout<<res.size()<<endl;
for (int i=0;i<res.size();i++)
cout<<fixed<<res[i]<<endl;

cin.get();cin.get();
return 0;}