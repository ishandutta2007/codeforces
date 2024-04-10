/*
Indestructible
On this rock I lie
But I'm alive for good
And I just free myself now
From all what was wrong
Break the unbreakable

All the stars
Fearlessly bright
They call me out there
Order me to face the wind
My structure's alive,
My body's on the way
Don't bow down
Before the walls
Of fear and madness
They try to counter me
And strike me down
To the ground again

Inexhaustible
The strength of fire
Is running through me
Spike like beam of light
What mortal could ever
Break this force
Unconstrained
I see at last
My backbone straighten
Thy serpent made of bones
Finally rise up
From the ground awaken

Beat your feet
On the ground now, go!
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

const int N = 200000;

using namespace std;

int n;
long long ar[N], s, me;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	me = 1e18;

	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		s += ar[i];
		if (ar[i] % 2)
			me = min(me, ar[i]);
	}
	if (s % 2)
		cout << s - me << endl;
	else
		cout << s << endl;

	cin.get(); cin.get();
	return 0;
}