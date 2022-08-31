/*
Waves of chaos all around
The birth of new religion
Rise from the underground
Empower enslave
Insurrection breaking down
In dark and brutal vision
Symphonic violent sound
The symbol is raised

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Pulling on the strings of hate
Sadistic revolution
Crushing subhuman faith
Objective engaged
Killing becomes industry
Defining resolution
War on impurity
Relentless campaign

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Death become the weak
Only strong will survive
Machine like propaganda
Fills a nation with pride
Hatred never seen
In the speeches of peace
From the designers of a dream
Only hell can unleash
Soldiers of the storm
Shock, divide and deploy
Elitist special forces
Operate and destroy
The sacrificial lamb
At the jaws of a beast
Total destruction of a kind
And religious belief

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order
The code is black
Rise
The code is black
The code, the code is black
The code, the code is black
The code, the code is black
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
#define prev asdfasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 2200;

using namespace std;

int n, ar[N], ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	for (int i = 1; i <= n; i++)
	{
		if (ar[i] == 1 || ar[i - 1] + ar[i + 1] == 2)
			++ans;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}