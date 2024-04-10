/*
Nothing I can do about it
Maybe I won't even try
Your will is determined to kill any
Reason of mine

I see you coming
With that look in your eye
You act like a king but you ain't got a
thing
In your mind

And now there's nobody home
My belly is aching
Your image is blown
Your lights are burning bright
But Nobody's Home

You talk about love and affection
If only you could
You're full of pride but there's nothing
inside
And you think you're so good

You know you got it coming to ya
All things return
You need me
It's not gonna be my concern

And now there's nobody home
Your message is changing
The children have grown
Your lights are burning bright
But nobody's home

I hear you crying
What can I say
You get what you give so
Forgive me as I turn away

Nobody's home
A legend is dying
The seeds have been sown
Your lights are burning bright
But Nobody's Home
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

long double R,x1,y1,x2,y2;

long double get_dist(long double x,long double y){
	return sqrt(x*x+y*y);
}

bool outside(){
	return get_dist(x2,y2)>R;
}

void show_answer(long double x,long double y,long double r){
	x+=x1;
	y+=y1;
	cout.precision(20);
	cout<<fixed<<x<<" "<<y<<" "<<r<<endl;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>R>>x1>>y1>>x2>>y2;
	x2-=x1;
	y2-=y1;
	if (outside()){
		show_answer(0,0,R);
	}
	else
	{
		long double D=get_dist(x2,y2);
		long double dir=atan2(y2,x2);
		dir=dir+M_PI;
		long double diam=R+D;
		long double rad=diam/2;
		rad-=D;
		long double ax=rad*cos(dir);
		long double ay=rad*sin(dir);
		//cout.precision(20);
		show_answer(ax,ay,rad+D);
	}
//	cin.get(); cin.get();
	return 0;
}