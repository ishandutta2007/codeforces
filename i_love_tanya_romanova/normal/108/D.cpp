/*
Listen, listen to me, can't you hear me?
Listen, I beg of you
I have escaped the one who rules deep in space
He knows my name, I know his game

Now that I'm here, he will know where I am
And he will get you too
And he will make you believe whatever he wants
Inside your brain, he'll play his game

Listen now, please, don't you believe
Whatever he says, whatever he says, whatever he says

I'm no preacher, I'm no space cowboy
I'm no flash in the pan
Don't you know that you have another thing coming?
You are not safe, here in this place

Are you aware you face your lat dead line?
I am here to warn you President X-D will be on your TV
Electron waves, a pixel face

Listen now, please, don't you believe
Whatever he says, whatever he says, whatever he says

You will never switch him off, when you're hypnotized
Don't you dare to call his bluff, he's well organized
You will never switch him off, when you're hypnotized
Don't you dare to call his bluff, he's well organized

He gets around, he gets around, he gets around, he
Listen to me, it's not easy, to let you be

Happy in your world, and you can't imagine
What will come from the milky way, far away
My words are clear, we can't stay here what do you fear?
Happy in your world, and you can't imagine
What will come from the milky way, far away

You, people of this world, be prepared to greet me
You, people of this world, you will submit to me
Deep into my third eye, you are getting sleepy
Deep into my third eye, now you belong to me

Now is the time, together we can change this place for the better
Now is the time, together we can change this place for the better

Now, focus on my voice, will you do it for me?
Now, focus on my voice, yes, you will do it for me
I'll give you everything but you must come to me
I'll give you everything but you'll have to join me

Now is the time, together we can change this place for the better
Now is the time, together we can change this place for the better
Now is the time, together we can change this place for the better
Now is the time, together we can change this place for the better

You will never switch him off, when you're hypnotized
Don't you dare to call his bluff, he's well organized

X-D is coming the sky is changing
X-D is coming my head is spinning

And what about Hydra, Sirrah, Pollux and Gemma
Diadem, Bellatrix, Mirach, Izar

Lies are what we once knew, time to live something new, hey hey
We can no longer take things for granted
We can now remember what we wanted, hey hey, hey hey

We're not slaves anymore, now we know what life is for
We don't fight anymore, he is what we're living for
We're not slaves anymore, now we know what life is for
We don't fight anymore not anymore

More than tears fill my eyes, as bright ships dot the sky
More than fear is in sight, as moon and sun stand by and cry

So this is the end, I'm leaving now, farewell my friends
X-D is now in control, making plans for his new home

Fate lights me from within, to the stars I'm fleeing
Earth heeds not my warning, forever sleepwalking dreaming

So this is the end, I'm leaving now, farewell my friends
Maybe one day, time will tell, I'll be back and break the spell
I'll break the spell, I'll break the spell
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

long n,m,h,ts,calc[2000];
double p2,p1;

double gc(long n,long m)
{
 if (m>n)return 0;
 double res=0;
 for (int i=n;i>n-m;i--)
  res=res+log(i+.0),res=res-log(.0+n-i+1);
 return exp(res);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>h;
for (int i=1;i<=m;i++)
{
 cin>>calc[i];
 ts+=calc[i];
}

if (ts<n){cout<<-1<<endl;return 0;}
if (n==1){cout<<0<<endl;return 0;}
if (calc[h]==1){cout<<0<<endl;return 0;}
--n;
--calc[h];
--ts;

double ans=1.0;
for (int i=1;i<=n;i++)
ans=ans*(ts-calc[h]-i+1)/(ts-i+1);

cout<<fixed<<1.0-ans<<endl;

cin.get();cin.get();
return 0;}