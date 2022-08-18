/*
Today's youth don't want a Volvo
They don't want a Jaguar
They don't want semi-dry wine
Mercedes is what they want!
Today's youth don't want a roll-on
They don't want model planes
They don't want curried beef and rice
Just Adidas is what they want!
Today's youth don't want Erica Young
They don't want T.S. Elliott
They want hard bodied idols
And just a bit more cash
Today's youth don't want Kmicic
They don't want race bikes
Every stupid dick is a super agent Bond
Cheap gas (you know) is what they want
But I don't want it!
But I don't need it!
I like to be who I am!
Today's youth don't wanna dive deep
They want the second hand emotion
They want the cheap drugs trip
And the long kiss in slow motion
Todays youth like XXL partys
But they have no money
The second class heroes, absolute zeroes
If something's wrong, they need mummy...
But I don't want it!
But I don't need it!
I like to be who I am!
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
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 21000000;

using namespace std;

long long answ;
int a, n;
int ans[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> n;

	for (int i = 1; i*i <= 2e7; i++)
	{
		for (int j = i*i; j <= 2e7; j += i*i)
			ans[j] = i*i;
	}

	for (int i = a; i < a + n; i++)
		answ += i/ans[i];

	cout << answ << endl;

	cin.get(); cin.get();
	return 0;
}