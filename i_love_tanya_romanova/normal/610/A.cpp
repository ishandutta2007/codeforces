/*
In a dark and brutal land
not far from here
Lived a mighty wargod
The slaves were all afraid
No one stood up against him
No one tried
He lived by his sword
Till he died

Mighty wargod fight till death
Hunt the people let no one rest
Show your planet who is the lord
Take the weapons made to strike

Fight under an immortal command
Spread fear across the land
Always trusting holy rule
Death is your saviour
Spread fear across the sea
Kill yourself to be free
The only commander of the world
Death is your saviour

In the night a constant fight
Death is in the air
Banshees crying through the sky
You don't know where
Look up high the corpses will live
All the genocide
Soldiers march on unholy ground
In front death is riding

Mighty wargod fight till death
Hunt the people let no one rest
Show your planet who is the lord
Take the weapons made to strike

Death is your saviour
You're gonna die
Burn in the fire
Scream across the sky
Death is your saviour
You're gonna die
All the survivors
Can hear you cry
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 510000;

using namespace std;

int n;
int solve(int x)
{
	if (x % 2)
		return 0;
	int res = x / 4;
	if (x % 4 == 0)
		--res;
	return res;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cout << solve(n) << endl;

	cin.get(); cin.get();

	return 0;
}