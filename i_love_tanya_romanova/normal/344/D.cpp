/*
Yeah yeah
Yeah yeah
Yeah yeah

Disease, disease
Spreading the disease
With some help from Captain Trips
Bringing the world down to his knees

Power, yes, power
Hell show them all his power
It pulses through his ice cold blood
A whole world to devour

Hes seeing, hes calling
His legacy, hes spawning
Hes coming, corrupting
Among the living

Murder, murder
Commit cold blooded murder
Like Nazis during World War II
They only follow orders

Hatred, hatred
The crucifix is your bed
Once he turns his eyes on you
Youll be better off dead

Hes seeing, hes calling
His legacy, hes spawning
Hes coming, corrupting
Among the living

Im the walking dude
I can see all the world
Twist your minds with fear
Im the man with the power
Among the living, follow me or die

Man fights man
Divided they cant stand
United, they can battle back
And make him force his hand

Fear, yes, fear
His end is growing near
He didnt count on mans good faith
Or the will to persevere

Hes seeing, hes calling
His legacy, hes spawning
Hes coming, corrupting
Among the living

Im the walking dude
I can see all the world
Twist your minds with fear
Im the man with the power
Among the living, follow me or die

Oh, fire, hot fire
Purge the world with fire
Damnation is the price hell pay
For an evil mans desire

Good versus evil
The stand to vanquish evil
Man can only live one way
That place right in the middle

Hes seeing, hes calling
His legacy, hes spawning
Hes coming, corrupting
Among the living

Im the walking dude
I can see all the world
Twist your minds with fear
Im the man with the power
Among the living, follow me or die

Among
Among
Among
...
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

string st;
stack<long> s;

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (s.size()==0)s.push(st[i]);
 else if (s.top()==st[i])
 {
      s.pop();
 }   
 else s.push(st[i]);
}

if (s.size())cout<<"No"<<endl;
else cout<<"Yes"<<endl;

cin.get();cin.get();
return 0;}