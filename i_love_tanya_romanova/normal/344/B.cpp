/*
Our star was out tonight
Our diamond shined so bright
I watched it go
Farther than he ever dreamed
I can't take it

No matter how I try
I can't stop asking why
'Cause something's broken
Scared it breaks my heart
I won't take it, can't break it

In the end
I'm pounding on the door
But It's already over
Too little, too late

In the end
He'll be my light in the dark
For when the sun goes down
When the sun goes down on me

And when the greatest falls
Heaven and Hell will call
Stand up and fight
On and on his memory screams
I can't take it

Stand up and fight withal
I won't take it, I can't break it

In the end
I'm pounding on the door
But It's already over
Too little, too late

In the end
They'll be my light in the dark
For when the sun goes down
For when the sun goes down

In the end
I'm kicking down the door
And I'm taking this over
I'm cleaning the slate

In the end
They'll be my light in the dark
For when the sun goes down
When the sun goes down on me

Did I thank you, for our time together?
Did I thank you, for making me better?
Did I thank you, for being the one I would
Bleed and kill for?
Did I thank you for tearing my head off?
Ripping my heart out
Fucking my world

Do we tell you how much we loved you?
Do we tell you you made our dreams come true?
Do we tell you you were the one?
Paving our way, the damage is done
Did we thank you for tearing our head off?
Ripping our hearts out
Fucking our world!

I can't break it

In the end
I'm pounding on the door
But It's already over
Too little, too late

In the end
He'll be my light in the dark
When the sun goes down
When the sun goes down

In the end
I'm pounding on the door
But It's already over
Too little, too late

In the end
He'll be my light in the dark
For when the sun goes down
When the sun goes down on me
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long a,b,c,da,db,dc,fl,aa,ab,ac;

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>c;
for (int fst=0;fst<=1000000;fst++)
{
 da=a-fst;
 db=b-fst;
 if (da<0||db<0)continue;
 if (da+db==c)
 {
             fl=1;
             aa=fst;ab=db;ac=da; 
 }   
}
if (fl)cout<<aa<<" "<<ab<<" "<<ac<<endl;
else
cout<<"Impossible"<<endl;

cin.get();cin.get();
return 0;}