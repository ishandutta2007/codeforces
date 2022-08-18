/*
Slap shot sucker shot
Down on your knees
Skate to the face
You're gouged and you bleed
Tussle and muscle
Flare like a rocket
Goon squad hired hit
A buck in the pocket

Blood on the ice
Blood on the ice

Puck shy, black eye
Jam in the corner
Tangled up, beat up
A body for the coroner

Blood on the ice

Pile up, punch out
In the end zone
Puck in the mouth
The sound of crushed bone

Blood on the ice
Blood on the ice
Blood on the ice

Shoot to score
Fight to kill
Play to win
Cheer for more

Rookie rabbit punches
Blow to blow
Duck and punch, dance
Toe to toe
Face off, square off
Cross check to the jaw
High stick, end butt
You wanna break the law

Blood on the ice
Blood on the ice
Pounding way to win the fight
Blood on the ice
Black and blue; red on white
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long long n,x,s,q;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>x;
for (int i=1;i<=n;i++)
{
 cin>>q;
 s+=q;
}
if (s<0)s=-s;
cout<<s/x+(s%x>0)<<endl;

cin.get();cin.get();
return 0;}