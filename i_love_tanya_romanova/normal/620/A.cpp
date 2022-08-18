/*
Business of false doctrine
Nothing is impossible
Wonders of technology
We got plastic surgery

Organ trading is of use
Unavoidable the abuse
Need some lungs and need some hearts
Searching for new body parts

Body parts

Bodies damaged after a crash
Transplanting skin to your flesh
That's no minor injury
This is plastic surgery

Rich and infamous bastard
You got a chance to survive
Replacing your diseased parts
Recover and stay alive

Body parts

Life is what you wanna buy
Unknown victims have to die
New organs is what you need
Nothing justified the deed

Business of false doctrine
Everything is possible
Wonders of technology
Because we got plastic surgery
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600000;

using namespace std;

int x1, y1, x2, y2;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> x1 >> y1 >> x2 >> y2;
	x1 = abs(x1 - x2);
	y1 = abs(y1 - y2);
	cout << max(x1, y1) << endl;

	cin.get(); cin.get();
	return 0;
}