/*
Empty spaces - what are we living for
Abandoned places - I guess we know the score
On and on, does anybody know what we are looking for...
Another hero, another mindless crime
Behind the curtain, in the pantomime
Hold the line, does anybody want to take it anymore
The show must go on,
The show must go on
Inside my heart is breaking
My make-up may be flaking
But my smile still stays on.
Whatever happens, I'll leave it all to chance
Another heartache, another failed romance
On and on, does anybody know what we are living for?
I guess I'm learning, I must be warmer now
I'll soon be turning, round the corner now
Outside the dawn is breaking
But inside in the dark I'm aching to be free
The show must go on
The show must go on
Inside my heart is breaking
My make-up may be flaking
But my smile still stays on
My soul is painted like the wings of butterflies
Fairytales of yesterday will grow but never die
I can fly - my friends
The show must go on
The show must go on
I'll face it with a grin
I'm never giving in
On - with the show -
I'll top the bill, I'll overkill
I have to find the will to carry on
On with the -
On with the show -
The show must go on...
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
 
#define  INF 100000000
#define eps 1e-11
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

long long n,q,ans;
map<long long, long long> mapp;

long long calc(long long n)
{long long s=0;
while (n){s+=n%2;n/=2;}
return s;
}

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    mapp[calc(q)]++;
}

for (int i=1;i<=30;i++)
ans+=mapp[i]*(mapp[i]-1)/2;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}