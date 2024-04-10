/*
When this began 
I had nothing to say 
And I'd get lost in the nothingness inside of me 
I was confused 
And I'd let it all out to find 
That I'm not the only person with these things in mind 
Inside of me 
When all the vacancy the words revealed 
Is the only real thing that I've got left to feel 
Nothing to loose 
Just stuck, hollow and alone 
And the fault is my own and the fault is my own 

I wanna heal 
I wanna feel 
What I thought was never real 
I want to let go of the pain I felt so long 
Erase all the pain till it's gone 
I wanna heal 
I wanna feel 
Like Im close to something real 
I want to find something I've wanted all along 
Somewhere I belong 

And I've got nothing to say 
I can't believe I didn't fall right down on my face 
I was confused 
Looking everwhere only to find 
That it's not the way I had imagined it all in my mind 
So what am I 
What do I have but negativity 
Cause I can't justify the way everyone is looking at me 
Nothing to lose 
Nothing to gain, hollow and alone 
And the fault is my own and the fault is my own 

I wanna heal 
I wanna feel 
What I thought was never real 
I want to let go of the pain I felt so long 
Erase all the pain til its gone 
I wanna heal 
I wanna feel 
Like Im close to something real 
I want to find something I've wanted all along 
Somewhere I belong 

I will never know 
Myself until I do this on my own 
And I will never feel 
Anything else, until my wounds are healed 
I will never be anything 
till I break away from me 
I will break away 
I'll find myself today 

I wanna heal 
I wanna feel 
What I thought was never real 
I want to let go of the pain I felt so long 
Erase all the pain till it's gone 
I wanna heal 
I wanna feel 
Like I'm close to something real 
I want to find something I've wanted all along 
Somewhere I belong 

I wanna heal 
I wanna feel 
I wanna feel like I'm somewhere I belong 

I wanna heal 
I wanna feel 
I wanna feel like I'm somewhere I belong 

Somewhere I belong
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m,c[10000],a,b,t;
double ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>c[i];

for (int i=1;i<=m;i++)
{
 cin>>a>>b>>t;
 ans=max(ans,(c[a]+c[b]+.0)/t);
}
cout.precision(13);

cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}