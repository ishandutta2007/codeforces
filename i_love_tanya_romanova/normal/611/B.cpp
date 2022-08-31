/*
The beast behind our eyes is loose
The day has come, the day has come
We march to Armageddon
Hungry for the war

I see the hated enemy
I see what I was taught to see
And one of us will bend the knee
We understand the law

The blood lust jerks our legs to march
Fife and drum, fife and drum
Our eyes are fixed and fearless
Searching for the war

Our statesmen deal in blood and lies
100 million stifled cries
100 million wasted lives
Already gone before

So march or die, march or die
The stench of death is in the sky
We never fail to satisfy
We rend with tooth and claw

Sword and shield and jackboot heel
We love to kill, we love to kill
We love to taste our own blood
Squirm in our own gore

Children weep and widows wail
Our education systems fail
To hide our guilt we build more jails
And we shall build still more

Our forests die, the stranglehold
That we put on the earth for gold
Will yet increase ten thousand fold
And no one knows what for

March and die, march and die
Defecate, despoil and lie
Cheat, dissemble, preach and spy
Build your house of straw

Laugh and cry, laugh and cry
Bloody sunset drowns the sky
For earth the heal then we must die
No-one deserves it more

I tell you we are doomed my friends
Our time is come, our time is come
We live within a channel house
Rotten to the core

We glorify lust, greed and pain
We drown our hope in poison rain
We point the finger, shift the blame
Ambition makes us whores

March or croak, march or croak
All your lives a cosmic joke
Fill your days with piss and smoke
The wolf waits at your door

Burn and dance, burn and dance
Sex, death, torture, false romance
Whoop and howl, you have no chance
Burn and rise no more
Burn and rise no more

Die
Die
Die
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 105000;

using namespace std;

vector<long long> v;

void generate(long long val, int z)
{
	if (z==1)
		v.push_back(val);
	if (val > 1e18)
		return;
	generate(val * 2 + 1, z );
	if (z == 0)
		generate(val * 2, z + 1);
}
long long ans;
long long l, r;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	generate(1, 0);

	//cout << v.size() << endl;

	cin >> l >> r;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= l&&v[i] <= r)
			ans++;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}