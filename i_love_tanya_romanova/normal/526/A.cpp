/*
Sun is low now in the sky
soon the cold will start to bite
and I'm kicking some old
empty can
down a barren street yah
step into a dark saloon
peer across the smoke filled room
I can feel her a mile away
she smiles and beckons me

Now we're dancing throught the mist
face to face I taste her breath
our gaze locks into a hazy trance I start to quiver
now she comes to comfort me I tell her I'm too blind to see
a warm bed and a fresh breath of air and you'll feel better

I know the feeling that you get
too bad it's only for a moment
lost in the shadows of the night
she turned and took my hand said
stay by my side, slip between the light
mirror my image we'll be alright

The key that opens up a thousand doors of mystery
unlocks a basement full of fears
start to unravel in it you might as well be blind
she saw my fright and closed her eyes

Don't fall in love it's a crazy nightmare
she looked at me and she winked an eye
it's too soon to say good-bye to this darktown
could use a fortune of imagination
refuse to look but I cannot deny
gotta make it out tonight of this darktown

Sorry to leave you in this crazy nightmare
she looked at and she winked and eye
that's too bad so goodbye to your darktown
could use a fortune of imagination
I turned to look but I closed my eyes
and I won't turn back tonight to this darktown
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,er;
string st;
long found;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int span=4;span<=n;span+=4)
{
 for (int start=0;start+span<st.size();start++)
 {
  er=0;
  if (st[start]=='.')er=1;
  if (st[start+span/4]=='.')er=1;
  if (st[start+2*span/4]=='.')er=1;
  if (st[start+3*span/4]=='.')er=1;
  if (st[start+span]=='.')er=1;
  if (er==0)found=1;
 }
}

if (found)cout<<"yes"<<endl;
else cout<<"no"<<endl;

cin.get();cin.get();
return 0;}