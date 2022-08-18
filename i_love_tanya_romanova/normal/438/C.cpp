/*
Fire falling from the sky
Rage of God is coming down
Armageddon's drawing nigh
Sinner cry, heathen die
Hear the toll of pain, Gloria, Gloria

In the fiery rain, fire falling from the sky
Rage of God is coming down
Armageddon's drawing nigh
Sinner cry heathen die
Hear the toll of pain, Gloria, Gloria

Now the time has come, the end's begun
And the only one will come

It has been foretold
By the visions of the old
And the madness in their eyes
Said his angel will arise
That's what they know
Holy Lord, it's over, oh God

We have done no wrong
So we go where we belong
To the never ending dream
But for those who lived in sin
They claim to know
Holy Lord it's over, oh God

Hey angel, can you tell me?
Will you lead us to the place?
Full of heat in the fire
For we only brought disgrace
He is not the one if they only knew

Hey angel, will you take us?
To the judgment of his rage
Hey, will we die
For we couldn't close the gate?

To the knowledge as they have been told

I don't know how could I prove
Nothing but the cloven hoof
Reigning over them as well
While they keep on fighting hell
Babylon, the scarlet whore has come

We are the seven, judgment of heaven
Why don't we know? We are the angels
It's revelation, soul castigation
Fire will burn us away

We are the seven, judgment of heaven
Why don't we know? We are the angels
It's revelation, soul castigation
Fire will burn us away

Redeemer, devastation
Hope it only has been ment
For the sin of the dreamer
Who broke the low you'd sent
He is not the one, if they only knew

Hey, don't know but I wondered:
When we lost the seal again
Maybe stoned by the incense
Do we rise or just descent
He is not the one, if they only knew

I don't know how could I prove
Nothing but the cloven hoof
Reigning over them as well
While they keep on fighting hell
Babylon, the scarlet whore has come

We are the seven, judgment of heaven
Why don't we know? We are the angels
It's revelation, soul castigation
Fire will burn us away

We are the seven, judgment of heaven
Why don't we know? We are the angels
It's revelation, soul castigation
Fire will burn us away

Woe to you longing for the wisdom
Woe to you longing for the light
All my sons bring me back what is mine
Or you'll end burning in this night

Woe to you longing for the wisdom
Woe to you longing for the light
All my sons bring me back what is mine
Or you'll end burning in this night

Once I have been lost
In what they told me to believe
Until I felt in burning
Deep inside to set my spirit free

And I escaped to another world
To help the little men
Who make me plunge into philosophy
To feel my mind again
No one left to hold me tight
On the real other side but her in chains

I had been alone till the madman come along
With the knowledge and silver long beard
He was the first man ever teaching how I could be free
Helping me to find, oh, the mind and the soul

They've been trying to hide away
And he promised we'd help Anna
If I'd help him to go all the way

Go all the way into the world of minds
Open the gate and do not close behind
Prevent them from hiding the light away
Prevent them from tellin' us tales
Or the end of all they scare us with
Will be a million empty brains

I could bring you what you told me
The seal they need to close the gate forever
But still I haven't found a meaning
Anna will we ever be together

You've been fighting for your soul
And sometimes it takes a toll
Hope one day you'll understand
What it means to hold in hands

What they call a fantasy
It is nothing but a key
To the world that now you're in
That they call a wicked dream

When you're walking on your own
When you're broken and alone
You may feel us from inside
On the other side of life, oh oh oh oh

I've been fighting for my soul
And sometimes it takes a toll
Hope one day we'll understand
What it means to hold in hands

What we call a fantasy
But it's nothing but a key
To the world that now I'm in
That we call a wicked dream

Oh, walking on my own
When I'm broken and alone
I may feel you from inside
From the other side of life
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,a,b,dp[300][300];
long long s;
vector<pair<long long,long long> > v;
long long r,tr;

long long gs(long long a,long long b,long long c)
{
 long long s=0;
 s=(v[b].first-v[a].first)*(v[c].second-v[a].second)-
 (v[b].second-v[a].second)*(v[c].first-v[a].first);
 return s;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>a>>b;v.push_back(make_pair(a,b));}

for (int i=0;i<n;i++)
 s+=v[(i+1)%n].first*v[i].second-v[(i+1)%n].second*v[i].first;

if (s<0)reverse(v.begin(),v.end());

for (int i=0;i<n;i++) 
 dp[i][(i+1)%n]=1;
 
for (int span=2;span<n;span++)
{
 for (int l=0;l<n;l++)
 {
  r=l+span;
  r%=n;
  for (int q=l+1;q<l+span;q++)
  {
   tr=q%n;
   if (gs(l,r,tr)>0)
   dp[l][r]=(dp[l][r]+dp[l][tr]*dp[tr][r])%bs;
  }
 }
}

cout<<dp[0][n-1]<<endl;

cin.get();cin.get();
return 0;}