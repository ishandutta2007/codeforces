/*
"Good evening sports fans and welcome to what should
prove to be the best game of the year.
Hello everyone, I'm johnny bigmouth, welcoming you to
the final game of the world championship.
We're expecting to see one helluva game tonight,
There's no love lost between these two teams.
Each drawing endless amounts of penalties:
We've had fights, cheap shots, name calling - everything we could ask for...
So now, we take you live and play... the game".
You gave it your all, you gave all you've got
You reached for the limit, you pushed till you dropped
You scratched and you clawed, you spilled out your guts
You gave them your oath and you signed it in blood
Bent over backwards, your body is sore
You gave them your life but they still wanted more
You carry the load, you dig deep inside
Blood, sweat and tears till the day that you die
The game... betrayed
This is how you get repaid
They're playing with your mind, they're playing with your head
How do you like your meal when you're being force fed
This is how you get repaid... the game
You crash and you burn, you've stood at the top
You faced all the pressure and took the cheap shots
Your body keeps dying, wealth is the gain
You fought all the battles and played through the pain
You scratch at the scabs, you swear when you bleed
You laughed at the stitches and lost your front teeth
Go through the therapy, break all your bones
Then comes the trade, you buy/sell your home
"Oh my... what a hit! did you see that? unbelievable...
That's gotta hurt. The abuse this boy takes night after night,
and he's still putting on quite a show for the fans.
This guy is worth every penny he makes... I tell ya... that's gotta hurt..."
You talk of the glories and memories gone past
A brilliant career though it could never last
You're down and you're bitter, your rings are in hock
There's pins in your knees and you limp when you walk
You take all the pills, make the pain go away
You've lost all your wealth but your agent's ok
Your children have left you, your wife did the same
Look what it got you, but man he could sure play the game
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

string st;
long calc,ans;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (i==0||st[i]==st[i-1])++calc;
 else {ans+=1-calc%2;calc=1;}
}
ans+=1-calc%2;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}