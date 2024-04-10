/*Have you heard what they said on the news today?
Have you heard what is coming to us all?
That the world as we know it will be coming to an end
Have you heard, have you heard?

He sees them in the distance where the darkened clouds roll
He could feel tension in the atmosphere
He would look in the mirror, see an old man now
Does it matter they survive somehow?

They said there's nothing can be done about the situation
They said there's nothing you can do at all
To sit and wait around for something to occur
Did you know, did you know?

As he stares across the garden looking at the meadows
And wonders if they'll ever grow again
The desperation of the situation getting graver
Getting ready when the wild wind blows

Have you seen what they said on the news today?
Have you heard what they said about us all?
Do you know what is happening to just every one of us
Have you heard, have you heard?

There will be a catastrophe the like we've never seen
There will be something that will light the sky
That the world as we know it, it will never be the same
Did you know, did you know?

He carries everything into the shelter not a fuss
Getting ready when the moment comes
He has enough supplies to last them for a year or two
Good to have because you never know

They tell us nothing that we don't already know about
They tell us nothing that is real at all
They only fill us with the stuff that they want
Did you know, did you know?

He's nearly finished with the preparations for the day
He's getting tired that'll do for now
They are preparing for the very worst to come to them
Getting ready when the wild wind blows

He sees the picture on the wall, it's falling down upside down
He sees a teardrop from his wife roll down her face, saying grace
Remember times they had, they flash right through his mind left behind
Of a lifetime spent together long ago will be gone

They've been preparing for some weeks now
For when the crucial moment comes
To take their refuge in the shelter
Let them prepare for what will come

They make a tea and sit there waiting
They're in the shelter feeling snug
Not long to wait for absolution
Don't make a fuss; just sit and wait

Can't believe all the lying,
All the screams are denying
That the moments of truth have begun

Can't you see it on the TV?
Don't believe them in the last bit
Now the days of our ending have begun

Say a prayer when it's all over
Survivors unite all as one
Got to try and help each other
Got the will to overcome

I can't believe all the lying,
All the screens are denying
That the moments of truth have begun

Can't you see it on the TV?
Don't believe them in the last bit
Now the days of our ending have begun

When they found them, had their arms wrapped around each other
Their tins of poison laying near by their clothes
The day they both mistook an earthquake for the fallout,
Just another when the wild wind blows...
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

long n,ar[200000];
stack<long> s;
long ans;

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
 while (s.size()>0&&s.top()<ar[i])
 s.pop();
 
 if (s.size()>0)
 ans=max(ans,ar[i]^s.top());
 
 s.push(ar[i]);   
}

reverse(ar,ar+n);
while(s.size())s.pop();


for (int i=0;i<n;i++)
{
// cin>>ar[i];
 while (s.size()>0&&s.top()<ar[i])
 s.pop();
 
 if (s.size()>0)
 ans=max(ans,ar[i]^s.top());
 
 s.push(ar[i]);   
}


cout<<ans<<endl;

cin.get();cin.get();
return 0;}