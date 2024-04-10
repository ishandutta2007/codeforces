/*
Follow the one evil masked in pride
Charisma to lead, speeches laced with hate
Leading the dense the bovine human herd
Inherently stupid, the fools deserve this fate

Warfare begins, cities are ablaze
Tortured screams, skin turning black
Carbonization, they will all burn
Mass execution, they will all die

Burning the world and all of it's life
Throwing all the people in a pit of fire
Watching the sheep gathering to die
Followers in life, follow to the grave

Follow the one evil masked in pride
Charisma to lead, speeches laced with hate
Leading the dense, the bovine human herd
Inherently stupid, the fools deserve this fate

Warfare begins, cities are ablaze
Tortured screams, skin turning black
Carbonization, they will all burn
Mass execution they will all die

Pile the bodies, set them aflame
The human race, sentenced to burn
Burning flesh, miasma of their death
Civilization, it is destroyed

Pits of corpses, unholy grave of war
Hanging victims, guilty of free thought

Warfare begins, cities are ablaze
Tortured screams, skin turning black
Carbonization, they will all burn
Mass execution, they will all die

Pile the bodies, set them aflame
The human race, sentenced to burn
Pile the bodies, set them aflame
The human race, sentenced to burn

War of fire shred their souls
Burn in hell doomsday's toll
Failed to see the trap they laid
Demagogues lead them into the flames

Pile the bodies, set them aflame
The human race, sentenced to burn
Pile the bodies, set them aflame
The human race, sentenced to burn
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

const int N = 200000;

using namespace std;

int n;
int ar[N];
int s;
int full, rem;
int need[N];
int ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		s += ar[i];
	}

	sort(ar, ar + n);

	full = s / n;
	rem = s%n;
	for (int i = 0; i < n; i++)
	{
		need[i] = full;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (rem == 0)
			continue;
		need[i]++;
		rem--;
	}

	for (int i = 0; i < n; i++)
	{
		if (ar[i]>need[i])
			ans += ar[i] - need[i];
	}

	cout << ans << endl;

	cin.get();
	return 0;
}