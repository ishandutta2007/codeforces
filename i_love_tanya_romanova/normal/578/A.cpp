/*
Looking deep down in living mirror
Don't you know the ancient was here
Something's really wrong over here
Where all of lost soul have to stay
Waiting for a day

Flying headlong swallows are maidens
Navyi cries for beauty and madness
Evermist and never tomorrow
All you've lost just sorrow

Looking deep down in living mirror
Don't you know the ancient was here
Something's really wrong over here
All you've lost not here

Deep Down!..
Living mirror
Let you out of your greasy fears
Your life is just one more
Awakening of your inner power
You know... You know... You know...

Living mirror's trap for the righteous
Strange reflections
Ice-cold and lightless
Guess you've got that
I was a liar
Now you're getting up higher
You know... You know... You know...
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int x,y;

double solve(int val,int lwr)
{
	if (val==0)
		return lwr;
		
	int ful=val/lwr;
	if (ful%2)
		--ful;
//	cout<<ful<<endl;
	if (ful==0)
		return 2e9;
	return val*1.0/ful;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>y;
if (y>x)
{
	cout<<-1<<endl;
	return 0;
}

double res1=solve(x-y,y);
double res2=solve(x+y,y);
cout.precision(12);
cout<<fixed<<min(res1,res2)<<endl;

//cin.get();cin.get();
return 0;}