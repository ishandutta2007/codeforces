/*
Show me a sign, show me a reason to give,
A solitary fuck about your god damn beliefs
I'm going blind, but one thing's clear
Death is the only salvation you'll feel

Brick by brick by brick
Brick by brick by brick

What you call faith, I call a sorry excuse
Cloak and daggers murder the truth
The bitter taste, there's nothing else
I'll bow for your king when he shows himself

Brick by brick by brick
These walls begin to cave in
The house of wolves you built
Whispers in a thousand tongues

Show me your face, show me a reason to think,
My soul can be saved if I sell you my sins
I'm going blind, but one thing's clear
Death is the only salvation for me

Brick by brick by brick
These walls begin to cave in
The house of wolves you built
Whispers in a thousand tongues

(The house of wolves you built)
(The nest of wolves you built)
The house of wolves you built
Will burn just like a thousand suns

When you die, the only kingdom you'll see
Is 2 foot wide and 6 foot deep

Yeah!

And when you die, the only kingdom you'll see
Is 2 foot wide and 6 foot deep
And when you die, the only kingdom you'll see
Is 2 foot wide and 6 foot deep, oh!

Brick by brick by brick
Brick by brick by brick
Brick by brick by brick
These walls begin to cave in
The house of wolves you built
Whispers in a thousand tongues

Brick by brick by brick
These walls begin to cave in
The house of wolves you built
Will burn just like a thousand suns

You said you want me
Now I'm here, now I'm here, now I'm here
You said you want me
Now I'm here, now I'm here, now I'm here
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 201000;

using namespace std;

long double x, y, z;
string astring;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> x >> y >> z;

	long double ans = -1e200;

	//1
	long double res1 = log(x)*pow(y, z);
	if (res1 > ans)
	{
		ans = res1;
		astring = "x^y^z";
	}

	//2
	res1 = log(x)*pow(z, y);
	if (res1 > ans)
	{
		ans = res1;
		astring = "x^z^y";
	}

	//3
	res1 = log(x)*y*z;
	if (res1 > ans)
	{
		ans = res1;
		astring = "(x^y)^z";
	}
	//4=3
	//5
	res1 = log(y)*pow(x, z);
	if (res1 > ans)
	{
		ans = res1;
		astring = "y^x^z";
	}
	//6
	res1 = log(y)*pow(z, x);
	if (res1 > ans)
	{
		ans = res1;
		astring = "y^z^x";
	}

	//7
	res1 = log(y)*x*z;
	if (res1 > ans)
	{
		ans = res1;
		astring = "(y^x)^z";
	}
	//8=7
	//9
	res1 = log(z)*pow(x, y);
	if (res1 > ans)
	{
		ans = res1;
		astring = "z^x^y";
	}
	//10
	res1 = log(z)*pow(y, x);
	if (res1 > ans)
	{
		ans = res1;
		astring = "z^y^x";
	}
	//11
	res1 = log(z)*x*y;
	if (res1 > ans)
	{
		ans = res1;
		astring = "(z^x)^y";
	}
	//12=11
	cout << astring << endl;

	cin.get(); cin.get();
	return 0;
}