/*
At the very first sound
There was just light
And then, a storm
Of time and space
Just came and struck
Created our time
In water life
We understand
It just only began
Forced to look to the sky
And wonder why
We cannot face the fact that
We're all scared now
Of mysteries of life
There is a mask that soon will fall
Before the strong embrace
Of love and might
Of light in the dark
I go for the quest
I have to give myself the answer
Enter now this place in the wild
I can see the glade
My feeling now is growing bigger
From the sky

I do feel like no one can save me
I am so alone and yet I cried
I called for help, forsaken
But now I know
The only way is to
Understand the living
Obey the rule of light
And face the fear
Inside out!

Lost, I found there a stone
Erected in line
With one of the brightest stars
Of all the night sky vault
And I took my time
Took off the moss
Washed away the dust
And gave a new lease of life
Its' mystical force
I grab it now
And praise this lord
Of earth and stone
Make passage for souls awaken
So it returns
To where it's always been
With the gods
Now coming, I feel the love
It comes from on high

I know the words
But now I fell it inside
It grows, it's there
And all it comes from the sky
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,ar[1200000],l,r,rem;
long minn[1200000];
long fst;
long mmove;
long temp,ans;
long tmove;
long iters;
int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
//ar[i]=i;
}

sort(ar+1,ar+n+1);

cin>>r>>l;

for (int i=l;i<=r;i++)
minn[i-l]=1200000000;

for (int i=1;i<=n;i++)
{
    if (i>1&&ar[i]==ar[i-1])continue;
    //if (ar[i]==1)continue;
    rem=l%ar[i];
    if (rem==0)fst=l;
    else fst=l+(ar[i]-rem);
//    cout<<fst<<endl;
    for (int q=fst;q<=r;q+=ar[i])
    if (q-ar[i]>=l)minn[q-l]=min(minn[q-l],q-ar[i]);
    
}

mmove=r-1;

for (int i=1;i<=n;i++)
if(r-r%ar[i]>=l)mmove=min(mmove,r-r%ar[i]);

//cout<<mmove<<endl;

while (r>l)
{
 ++ans;
 tmove=mmove-1;
 for (int i=r;i>mmove;--i)
 tmove=min(tmove,minn[i-l]);
  
 r=mmove;
 mmove=tmove;
}
//cout<<iters<<endl;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}