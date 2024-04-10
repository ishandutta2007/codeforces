/*
Late at night all systems go
You have come to see the show
We do our best You're the rest
You make it real you know
There is a feeling deep inside
That drives you fuckin' mad
A feeling of a hammerhead
You need it oh so bad

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Bang your head against the stage
Like you never did before
Make it ring Make it bleed
Make it really sore
In a frenzied madness
with your leather and your spikes
Heads are bobbing all around
It is hot as hell tonight

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Here on the stage the Marshal noise
is piercing through your ears
It kicks your ass kick your face
Exploding feeling nears
Now is the time to let it rip
To let it fuckin' loose
We are gathered here to be with you
Cause this is what we choose

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

The show is through the metal is gone
It is time to hit the road
Another town Another gig
Again we will explode
Hotel rooms and motorways
Life out here is raw
But we will never stop
We will never quit
cause we are Metallica

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;
long long x,y,m,n,ans,span;

long long solve(long long x,long long y,long long m)
{
     if (max(x,y)>=m)return 0;
     if (x<=0&&y<=0)return -1;
     
     if (x>y)swap(x,y);
     ans=0;
     if (x<0){span=-x;
     ans=span/y;
     x+=ans*y;}
     
     while (x<m&&y<m)
     {
           if (x<y){x+=y;} else y+=x;
           ++ans;
     }
     return ans;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>y>>m;

cout<<solve(x,y,m)<<endl;

cin.get();cin.get();
return 0;}